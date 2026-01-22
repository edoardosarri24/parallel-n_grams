# todo
- rinominare P in hash_table.c
- Isolamento di ogni componente nel percorso di analisi del kgram. in pratica voglio vedere se il codice è lineare o può essere semplificato.
- capire:
    Alignment (Bitwise Magic):
        size = (size + alignment - 1) & ~(alignment - 1);
        Arrotonda la dimensione richiesta al multiplo superiore di 8 byte (su 64-bit).
        * Esempio: Se chiedi 13 byte -> diventa 16. Se chiedi 2 -> diventa 8.
        * Questo è cruciale per evitare "bus error" o rallentamenti hardware quando si accede a interi/puntatori non allineati in memoria.