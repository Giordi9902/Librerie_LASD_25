# Librerie LASD 2025

Raccolta di implementazioni di **strutture dati** e relativi esercizi per il corso di *Laboratorio di Algoritmi e Strutture Dati (LASD)*.  
Il progetto è organizzato in più esercizi, ognuno dei quali contiene diverse librerie e test per verificare il corretto funzionamento delle strutture.

---

## Struttura della repository
```
Librerie_LASD_25/
├── Exercise1
│   ├── container/    # Interfacce e classi base per contenitori
│   ├── list/         # Implementazioni di liste
│   ├── set/          # Implementazioni di insiemi
│   │   ├── vec/      # Implementazione di insiemi basati su vettori
│   │   └── lst/      # Implementazione di insiemi basati su liste
│   ├── vector/       # Implementazioni di vettori dinamici
│   ├── utils/        # Funzioni di supporto
│   ├── zlasdtest/    # Test forniti dal docente
│   ├── zmytest/      # Test personalizzati
│   ├── main.cpp      # Entry point dell'esercizio
│   └── makefile
└── Exercise2
    ├── container/    # Interfacce e classi base per contenitori
    ├── heap/         # Implementazioni di heap
    │   └── vec/      # Heap basato su vettore
    ├── list/         # Liste
    ├── pq/           # Code con priorità
    │   └── heap/     # Priority queue basata su heap
    ├── set/          # Insiemi
    ├── vector/       # Vettori dinamici
    ├── utils/        # Funzioni di supporto
    ├── zlasdtest/    # Test forniti dal docente
    ├── zmytest/      # Test personalizzati
    ├── main.cpp      # Entry point dell'esercizio
    └── makefile

```
---

## Compilazione ed esecuzione

Ogni esercizio è indipendente e può essere compilato separatamente.

### Esercizio 1
```bash
cd Exercise1
make
./main
```
### Esercizio 2
```bash
cd Exercise2
make
./main
```
---

## Strutture dati implementate

### Exercise 1

* Contenitori generici (container/)
* Liste (`list/`)
* Vettori (`vector/`)
* Insiemi (`set/`)

### Exercise 2
* Heap (`heap/`)
* Code con priorità (`pq/`)

## Test

Ogni esercizio contiene due cartelle di test:

- `zlasdtest/` → test ufficiali forniti dal docente

- `zmytest/` → test scritti dall’autore per casi aggiuntivi

Per eseguire i test, lanciare l’eseguibile compilato (./main) e selezionare i casi di interesse.

### Requisiti

* Compilatore C++17 o superiore

* `make` installato sul sistema

### Licenza

Distribuito con licenza [MIT](./LICENSE).

Puoi usarlo liberamente per studio, esercizio o come base per i tuoi progetti.
