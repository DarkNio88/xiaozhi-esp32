#ifndef OGG_DEMUXER_H_
#define OGG_DEMUXER_H_

#include <functional>
#include <cstdint>
#include <cstring>
#include <vector>

class OggDemuxer {
private:
    enum ParseState : int8_t {
        FIND_PAGE,
        PARSE_HEADER,
        PARSE_SEGMENTS,
        PARSE_DATA
    };

    struct Opus_t {
        bool    head_seen{false};
        bool    tags_seen{false};
        int     sample_rate{48000};
    };


    // Usa buffer a dimensione fissa per evitare allocazioni dinamiche
    struct context_t {
        bool packet_continued{false};   // Se il pacchetto è distribuito su più segmenti
        uint8_t header[27];             // Intestazione pagina Ogg
        uint8_t seg_table[255];         // Tabella dei segmenti memorizzata
        uint8_t packet_buf[8192];       // Buffer pacchetto (8 KB)
        size_t packet_len = 0;          // Lunghezza dei dati accumulati nel buffer
        size_t seg_count = 0;           // Numero di segmenti nella pagina corrente
        size_t seg_index = 0;           // Indice del segmento attualmente elaborato
        size_t data_offset = 0;         // Byte letti nella fase di parsing corrente
        size_t bytes_needed = 0;        // Byte ancora necessari per completare il campo corrente
        size_t seg_remaining = 0;       // Byte rimanenti da leggere nel segmento corrente
        size_t body_size = 0;           // Dimensione totale del corpo dati
        size_t body_offset = 0;         // Byte già letti del corpo dati
    };
    
public:
    OggDemuxer() {
        Reset();
    }
    
    void Reset();
    
    size_t Process(const uint8_t* data, size_t size);

    /// @brief Imposta la callback chiamata al termine del demuxing
    /// @param on_demuxer_finished Callback: (data, sample_rate, len)
    void OnDemuxerFinished(std::function<void(const uint8_t* data, int sample_rate, size_t len)> on_demuxer_finished) {
        on_demuxer_finished_ = on_demuxer_finished;
    }
private:

    ParseState  state_ = ParseState::FIND_PAGE;
    context_t   ctx_;
    Opus_t      opus_info_;
    std::function<void(const uint8_t*, int, size_t)> on_demuxer_finished_;
};

#endif