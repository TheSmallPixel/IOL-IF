# Appunti Strutturati delle Lezioni

Di seguito, una raccolta di appunti strutturati (in Markdown) relativi alle trascrizioni fornite. Ogni sezione corrisponde a **Lezione X modulo Y** e riassume i punti principali trattati nel contenuto audio.

---

## Lezione 1 modulo 2
**Tema principale**: Sistemi informativi, concetti base e parti informatizzate / non informatizzate.
- **Definizioni iniziali**  
  - Sistemi informativi come risorsa centrale per decisioni e operazioni di un’organizzazione.  
  - Differenza tra “sistema informativo” (incluso quello non informatizzato) e “sistema informativo informatizzato” (basato su IT).
- **Tre componenti chiave**  
  - Applicazioni software.  
  - DBMS (gestione dei dati) e basi di dati.  
  - Reti (per lo scambio di informazioni con l’esterno).
- **Distinzione tra parte automatizzata e non**  
  - Un sistema informativo comprende sia aspetti informatizzati sia aspetti manuali.  
  - Obiettivo del corso: progettare, gestire e controllare la parte informatizzata.
- **Due elementi fondamentali: dati e processi**  
  - **Piramide della conoscenza (DIKW)**: dati → informazioni → conoscenza → (saggezza).  
  - **Processi**: sequenze di attività con ruoli di attori (persone o sistemi).

---

## Lezione 1 modulo 3
**Tema principale**: Tipologie di sistemi informativi (operazionali e decisionali), OLTP vs. OLAP.
- **Caratteristiche dei sistemi operazionali**  
  - Supportano attività operative (transazioni, registrazioni...).  
  - Strutturazione di dati ben definita, focus sulla scrittura e aggiornamento rapido.
- **Caratteristiche dei sistemi decisionali (informazionali)**  
  - Supportano i livelli manageriali/strategici, dati spesso esterni, meno strutturati.  
  - Focus sulla lettura e analisi di grandi volumi di dati.
- **Distinzione OLTP vs OLAP**  
  - **OLTP**: tante transazioni elementari, dati correnti, scrittura frequente.  
  - **OLAP**: interrogazioni complesse e analisi storiche, dati aggregati, scrittura rara.
- **Progettazione di un sistema informativo**  
  - Requisiti aziendali e/o spinta tecnologica (Technology Push).  
  - Fattori ambientali (cultura, organizzazione) e strategici/politici.

---

## Lezione 2 modulo 1
**Tema principale**: Introduzione al linguaggio Archimate per rappresentare Enterprise Architecture.
- **Archimate**  
  - Linguaggio grafico con semantica definita, gestito da TheOpenGroup.  
  - Versione 3.1 (oggetto del corso), ma è disponibile la 3.2 in fase di adozione.
- **Fonti di studio**  
  - *Mastering ArchiMate* di Gerben Wierda (capitolo iniziale gratuito).  
  - *Enterprise Architecture at Work* di Marc Lankhorst.  
  - Gitbook collaborativo su Archimate.
- **Obiettivo**: mediazione tra aspetti business e aspetti IT.  
  - Progetto e gestione dell’Enterprise Architecture in modo comprensibile a entrambi i mondi.  
  - Core framework: business layer, application layer, technology layer, con aspetti attivi, comportamentali, passivi.
- **Strutturazione a layer**  
  - Ogni livello (business, application, technology) suddiviso in **servizi** (interfacce visibili) e **implementazioni**.  
  - Possibilità di diagrammare in modalità “layered”.

---

## Lezione 2.2
**Tema principale**: Familiarizzare con Archi (strumento software per Archimate).
- **Interfaccia di Archi**  
  - **Canvas centrale**: area per il disegno del diagramma.  
  - **Palette** (a destra): elenco di simboli Archimate (relazioni, elementi attivi, passivi, comportamentali...).  
  - **Modello (a sinistra)**: cartelle che raccolgono gli elementi creati.
- **Creazione di un nuovo modello**  
  - Opzioni: `File → New → Empty Model` oppure tasto destro → *Empty Model*.  
  - **Views** (diagrammi) organizzate in cartelle, ad es. *Business View*.
- **Cancellazione di elementi**  
  - *Delete from View*: rimuove solo dal diagramma corrente.  
  - *Delete from Model*: rimuove ovunque dal modello.
- **Relazioni con Magic Connector**  
  - **Assignment**, **Access**, **Trigger**, **Association** ecc., suggerite dal menù contestuale in base al contesto (bacchetta magica).

---

## Lezione 2.3
**Tema principale**: Modello Archimate per il *Business Layer*.
- **Elementi attivi**: *Business Actor*, *Business Role*, *Business Interface*, *Business Collaboration*.  
  - *Actor* = entità (cliente, impiegato…) con capacità di eseguire azioni.  
  - *Role* = insieme di responsabilità (es.: “assicurato”).  
  - *Interface* = punto di accesso ai servizi di business.  
  - *Collaboration* = aggregazione di attori/ruoli che collaborano.
- **Elementi comportamentali**: *Process*, *Function*, *Service*, *Event*.  
  - *Process* = sequenza di attività per un obiettivo.  
  - *Function* = insieme di attività raggruppate per affinità (es. stesse risorse).  
  - *Service* = funzionalità offerta all’esterno.  
  - *Event* = cambiamento di stato.
- **Elementi passivi**: *Business Object*, *Contract*, *Product*.  
  - *Business Object* = concetto rilevante per l’organizzazione.  
  - *Contract* = accordo formale, specializzazione del *Business Object*.  
  - *Product* = aggregatore di servizi/oggetti passivi.
- **Modelli dei processi**  
  - Modello di Anthony (controllo operativo/direzionale/strategico) e Porter (processi primari/supporto).  
  - *Basic Business Pattern* in Archimate: attore (customer) → interfaccia di business → servizio → (realizzato da) processo → (assegnato a) ruolo.

---

## Lezione 2.4
**Tema principale**: Esempi di utilizzo di Archi per il *Business Layer*.
- **Creazione di un modello di esempio**  
  - Esempio “Speedy”, servizio di report personalizzati (manager → data analyst).  
  - Struttura: *Business Service* (Customized Reporting Service) realizzato da *Business Process* (Customize Reporting Process).
- **Arricchimenti**  
  - Possibilità di scomporre il processo in fasi (receive details, check, tool development, delivery...).  
  - Possibilità di aggiungere dimensione automatizzata (self-service via web) → “Self Service Customized Report Service”.
- **Altri esempi**  
  - Azienda di assicurazioni: *Business Process* con alternative XOR event-based (affidabile/non affidabile).  
  - Gestione di contratti, scambio di documenti, Ruoli (es.: valutatore, rappresentante legale) con assegnamento a sotto-fasi del processo.

---

## Lezione 3 modulo 1
**Tema principale**: Introduzione ai processi aziendali (Business Process) e definizioni fondamentali.
- **Definizioni di *Business Process***  
  - Collezione di eventi, attività e decisioni, con attori e oggetti, diretti a un obiettivo di valore per il *customer*.  
  - Eseguito in un contesto organizzativo, può interagire con processi di altre organizzazioni.
- **Caratteristiche**  
  - Coordinamento delle attività e scambi informativi, spesso con coinvolgimento di IT.  
  - Obiettivo: raggiungimento di una finalità di business (valore aggiunto).
- **Tipologie di processi**  
  - **A vari livelli**: astratti vs. concreti/eseguibili; orchestrati vs. coreografati; manuali vs. automatizzati; strutturati vs. ad hoc.  
  - Necessità di *conformance* e *compliance* con modelli e norme.
- **Business Process Management (BPM)**  
  - Disciplina con metodi e tecniche per progettare, amministrare, configurare, eseguire e analizzare processi.  
  - Ciclo di vita: *Design & Analysis* → *Configuration* → *Enactment* → *Evaluation*.

---

## Lezione 3 modulo 2
**Tema principale**: Identificazione dei processi di un’organizzazione.
- **Struttura dei processi**  
  - (Input → Fasi → Attività → Operazioni) → Output.  
  - Livelli di dettaglio da definire in base al costo/beneficio dell’analisi.
- **Approcci**  
  1. **Check List**: basarsi su liste di riferimento (es. APQC), confronto con modelli standard di settore.  
     - Vantaggio: facile, ma limitato a settori regolamentati.  
  2. **Catena del valore di Porter**: individua processi primari e di supporto.  
     - Limite: orientata a unità organizzative, poco adatta ai servizi puri.  
  3. **Analitico (top-down)**: partire dal destinatario (cliente/fornitore...) e dall’output corrispondente.  
     - Più completo, ma anche più costoso. Buono per processi primari.

---

## Lezione 3 modulo 3
**Tema principale**: Introduzione a BPMN (Business Process Model and Notation).
- **BPMN**: standard OMG per rappresentare processi con diagrammi grafici.  
  - Elementi principali: *Attività*, *Eventi*, *Gateway*, *Flow*.
- **Attività**: rettangolo dai bordi arrotondati.  
  - Sequenza rappresentata dal *Flow* (freccia).  
  - Inizio/fine con cerchi (start event, end event).
- **Gateway**  
  - **XOR**: ramificazione e join in alternativa. Consente strutture di *split* (diverge) e *join* (converge).  
  - **AND**: attività in parallelo, *split* e *join* paralleli.
- **Cicli in BPMN**  
  - Possibile con XOR (ritorno indietro) o con notazione di loop su attività.  
  - Timer per gestire attese e scadenze.

---

## Lezione 4 modulo 1
**Tema principale**: Concetti avanzati di BPMN (eventi, sotto-processi, loop, multi-instance...).
- **Eventi**  
  - Possono essere di inizio, intermedi, finali (cerchio semplice, doppio bordo, bordo spesso).  
  - Tipologie: *Message*, *Timer*, *Error*, *Signal*, *Conditional*, *Terminate*.
- **Sotto-processi**  
  - Consentono di scomporre attività complesse in un processo a sé (diagramma interno).  
  - Possibile disegnare all’interno o in un diagramma separato.
- **Loop e Multi-instance**  
  - **Loop** su singola attività: ripetizione condizionale.  
  - **Multi-instance**: esecuzione parallela (o sequenziale) di N istanze della stessa attività.
- **Event-Based Gateway**  
  - Attesa di eventi diversi (es. messaggio di conferma o timer). Prende il primo che arriva.

---

## Lezione 4 modulo 2
**Tema principale**: Altri concetti avanzati BPMN, esempi più complessi.
- **Tipologie di eventi speciali**  
  - *Error* (fulmine): usato per interrompere un sotto-processo.  
  - *Signal* (throw/catch): inviato globalmente a più rami del processo.
- **Sotto-processi con *Terminate***  
  - Termina tutte le attività in esecuzione in quel sotto-processo.
- **Eventi boundary**  
  - Associazione di un evento intermedio al bordo di un’attività, per gestire eccezioni (timeout, error...).  
- **Event-Based XOR**  
  - Multi-possibilità: arrivo di diversi messaggi, timer diversi, segnali. Seleziona per primo arrivo.

---

## Lezione 4 modulo 3
**Tema principale**: *Collaboration Diagram* in BPMN, interazioni fra più processi (più *pool*).
- **Pool**  
  - Rappresentano partecipanti (aziende/divisioni) in un diagramma di collaborazione.  
  - *Black box*: nessun dettaglio di processo interno.  
  - *White box*: si mostra il processo interno.
- **Scambio di messaggi**  
  - *One-Way* (unidirezionale).  
  - *Request-response* (bloccante, scambio sincrono).  
  - Usati *Message Task* (send/receive) o *Intermediate Events*.
- **Multi-instance Pool**  
  - Rappresenta più istanze con lo stesso comportamento. Necessario correlare richieste e risposte (logica di *matching*).
- **Errori tipici**  
  - Uso errato di data-based XOR invece di event-based XOR per scelte condizionate da eventi esterni.  
  - Mancata sincronizzazione (deadlock) se un pool termina e l’altro rimane in attesa di ulteriori messaggi.

---

## Lezione 5 modulo 1
**Tema principale**: Componenti tecnologici a livello applicativo, cenni generali (ERP, CRM, DWH, ecc.).
- **Livelli**  
  - *Applicativo*: ERP, CRM, DataWarehouse, BI, MES, APS...  
  - *Piattaforma*: DBMS, BPM, gestione interfaccia...  
  - *Infrastruttura fisica*: macchine, reti, cloud.
- **ERP e CRM**  
  - Sistemi gestionali che forniscono funzioni integrate per processi aziendali.  
  - La scelta “Make or Buy” dipende da esigenze e costi/benefici.  
- **Integrazione**  
  - Diversi moduli applicativi devono scambiare dati in modo coerente. Importante usare componenti di piattaforma (middleware, bus...).

---

## Lezione 5 modulo 2
**Tema principale**: Componenti a livello applicativo: ERP (Enterprise Resource Planning).
- **Caratteristiche**  
  1. **Modularità** (funzioni separate in moduli).  
  2. **Unicità dell’informazione** (un unico database logico).  
  3. **Prescrittività** (processi predefiniti a cui adattarsi).
- **ERP Core** vs **ERP esteso**  
  - **Core**: moduli settoriali (produzione, logistica, vendite…) + moduli di supporto (amministrazione, risorse umane...) + funzioni direzionali (controllo, pianificazione).  
  - **Esteso**: include anche SCM, PLM, portali, funzionalità CRM avanzata...
- **Implementazione**  
  - **Parametrizzazione**: scegliere e impostare processi, lingue, dati.  
  - **Personalizzazione**: sviluppi ad hoc aggiuntivi (se necessari).
- **Evoluzione storica**  
  - Anni ‘80: MRP e sistemi produttivi integrati.  
  - Anni ‘90: ERP con client-server.  
  - Anni 2000: web application e servizi (SaaS, architetture SOA…).

---

## Lezione 5 modulo 5
**Tema principale**: Miglioramento del protocollo ALOHA tramite “Listen Before Talk” (CSMA).
- **ALOHA**  
  - Protocollo opportunistico, trasmissione senza ascolto.  
  - Molte collisioni.
- **CSMA** (Carrier Sense Multiple Access)**  
  - La stazione ascolta il canale prima di trasmettere.  
  - Collisioni ancora possibili per ritardi di propagazione o inizio trasmissioni quasi simultaneo.
- **CSMA/CD** (Collision Detect)  
  - Ethernet classico: se avviene collisione, chi trasmette se ne accorge e interrompe.  
  - Maggiore efficienza, evita di occupare il canale con il resto della trasmissione inutile.
- **Prestazioni**  
  - Dipendono da ritardo di propagazione (parametro *a*).  
  - Se *a* è piccolo, CSMA/CD ha throughput più alto rispetto a ALOHA.

---

## Lezione 5 modulo 6
**Tema principale**: Tecnologia Ethernet e standard 802.3 per reti locali.
- **IEEE 802**  
  - Gruppo di lavoro che standardizza reti locali (802.3 Ethernet, 802.11 Wi-Fi, ecc.).  
  - Distinzione tra LLC (802.2) e MAC (802.x).
- **Evoluzione Ethernet**  
  - Inizialmente cavo coassiale (10Base5, 10Base2).  
  - Anni ‘90: topologia a stella con HUB e doppini in rame (10BaseT).  
  - Aumento velocità: 100 Mbps (Fast Ethernet), 1 Gbps, 10 Gbps...
- **Trama Ethernet**  
  - Preambolo + Start Frame Delimiter + Indirizzi sorgente/destinazione + (eventuale) Type/Lenght + Dati + Frame Check Sequence.  
  - Indirizzi MAC a 48 bit (6 byte), unici per scheda di rete, indirizzo broadcast = FF:FF:FF:FF:FF:FF.

---

## Lezione 5 modulo 7
**Tema principale**: CRM (Customer Relationship Management).
- **Multicanalità**  
  - Canali inbound (cliente contatta azienda) e outbound (azienda offre prodotti).  
  - Integrazione delle informazioni e dei dati del cliente su tutti i canali.
- **Tre moduli del CRM**  
  1. **Operativo** (marketing, vendite, servizi).  
  2. **Analitico** (analisi dati e profilazione).  
  3. **Collaborativo** (KPI, obiettivi strategici).
- **CRM Operativo**  
  - *Marketing*: generazione liste, campagne, cross-selling/upselling.  
  - *Vendite*: gestione contatti, offerte, ordini.  
  - *Servizi al cliente*: contact center (call center, chat, web self-service...).
- **CRM Analitico**  
  - Reporting, profilazione segmenti cliente, analisi predittiva (churn).  
  - Spesso basato su Data Warehouse o tool di BI.
- **Benefici**  
  - Migliore efficienza (processi di contatto) e maggiore efficacia (personalizzazione, fidelizzazione).

---

## Lezione 5 modulo 8
**Tema principale**: VLAN (Virtual LAN) in reti locali commutate.
- **Obiettivo**: creare reti locali logicamente separate su un’unica infrastruttura fisica.  
  - Esempio: separare studenti, professori, amministrativi su uno stesso *switch*.
- **Protocollo 802.1q (tagging)**  
  - Incapsula un *tag* nelle trame di livello 2.  
  - Campi principali nel tag: *priorità*, *flag di drop*, *ID VLAN*.  
  - Switch instradano pacchetti anche in base a VLAN ID (non solo MAC).
- **Architettura**  
  - Struttura fisica di tipo *albero* con switch gerarchici.  
  - Si definiscono VLAN logiche separate (diversi ID) per segmentare il traffico.

---

## Lezione 6 modulo 1
**Tema principale**: Livello applicativo, introduzione al concetto di OLTP vs. OLAP, DataWarehouse, Business Intelligence.
- **Richiamo piramide di Anthony**  
  - OLTP = transazioni operative, dati correnti.  
  - OLAP = analisi storica su dati aggregati, con funzionalità di *Business Intelligence*.
- **Strumenti**  
  - *Report* statici, *fogli di calcolo* (Excel) per analisi base, ma con limiti di coerenza e scalabilità.  
  - Necessità di DB dedicati (DataWarehouse) per query complesse di tipo analitico.
- **Caratteristiche dell’analisi (BI)**  
  - Query su grandi volumi di dati, dimensioni multiple (tempo, località, prodotto...).  
  - Dati storici, integrati, aggregati, focus sulla lettura.

---

## Lezione 6 modulo 2
**Tema principale**: Modellazione e architettura dei Data Warehouse (DW).
- **Fasi**  
  1. *Estrazione (Extraction)* dei dati da varie fonti.  
  2. *Trasformazione (Transformation)*: pulizia, riconciliazione, standardizzazione.  
  3. *Caricamento (Loading)* nel Data Warehouse.
- **Struttura a ipercubo**  
  - Fatti, misure, dimensioni.  
  - Dimensioni con gerarchie (es. data → mese → trimestre → anno).
- **Modello concettuale** (Dimension Fact Model)  
  - Identifica i “fatti” (es.: vendite) e le “dimensioni” (es.: tempo, prodotto, luogo).  
  - Definisce gerarchie per l’aggregazione.
- **Schemi logici**  
  - **MOLAP** (multidimensionale puro).  
  - **ROLAP** (relazionale, star schema o snowflake schema).  
  - **HOLAP** (ibrido).  

---

## Lezione 7 modulo 1
**Tema principale**: Data Mining e estrazione di conoscenza dai dati.
- **Processo di Knowledge Discovery**  
  - Selezione, pulizia, integrazione, trasformazione dei dati → Data Mining → valutazione → presentazione.  
  - Spesso parte da un Data Warehouse ben strutturato.
- **Disciplina**  
  - Intersezione di *gestione dati*, *machine learning/statistica*, *sviluppo software*.  
  - Architetture di riferimento (NIST) per i *Big Data*.
- **Tipologie di apprendimento**  
  - **Supervisionato**: esiste variabile target (etichetta) su un dataset di training.  
  - **Non supervisionato**: nessuna etichetta, si cercano pattern/regolarità.  
- **Tecniche**  
  - *Regole associative* (descrittivo, non supervis.), *Classificazione* (predittivo, supervis.), *Clustering* (descrittivo, non supervis.).  

