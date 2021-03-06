#ifndef STARTER_H
#define STARTER_H

#include <QWidget>
#include <QtGui>
#include "mainwindow.h"
#include "main.h"
#include "cassert"
#include "debug.h"
#include "closingalert.h"
#include "about.h"

class MainWindow;
#ifdef DEBUG_MODE
class Debug;
#endif

/**
 *  The Starter class.
 *
 * Widget di apertura del programma.
 * Tramite esso é possibile impostare le dimensioni e il pattern della coltura.
 * Fatto ciò, la gestione viene passata a ::MainWindow.\n
 *  La parte pubblica contiene:
 *      - explicit Starter(QWidget *parent = 0)
 *      - ~Starter()
 *
 * I private slots sono:
 *      - void avvio(), che gestisce l'apertura della nuova coltura
 *      - void changeXDimension(int), che imposta la larghezza della coltura
 *      - void changeYDimension(int), che imposta l'altezza della coltura
 *      - void setPattern(int), che imposta il pattern
 *      - void load(), che carica una coltura da file
 *      - void openAbout(), che visualizza le informazioni sul programma
 *      - void closing(), che gestisce la terminazione del programma
 *
 * La parte protected contiene:
 *      - void closeEvent(QCloseEvent * closeEvent);
 *
 * La parte privata contiene:
 *      - MainWindow * mainwindow;
 *      - int dx;
 *      - int dy;
 *      - int pattern;
 *      - ClosingAlert * closingalert;
 *      - About * about;
 *      - Debug * debug, (!solo se in modalità debug!)
 */
class Starter : public QMainWindow
{
    Q_OBJECT
public:
    /**
     *  Costruttore della classe Starter.
     * @param parent 0
     */
    explicit Starter(QWidget *parent = 0);

    ~Starter();

private slots:
    /**
     *  Funzione che apre il widget MainWindow e chiude lo Starter.
     * Viene chiamata quando premo il pulsante "ok".
     */
    void avvio();

    /**
     *  Setta la larghezza della coltura.
     * Invocato ad ogni cambiamento di valore dello spinbox.
     */
    void changeXDimension(int);

    /**
     *  Setta l'altezza della coltura.
     * Invocato ad ogni cambiamento di valore dello spinbox.
     */
    void changeYDimension(int);

    /**
     *  Setta il pattern scelto.
     */
    void setPattern(int);

    /**
     *  Carica una coltura da file.
     */
    void load();

    /**
     *  Visualizza le informazioni sul programma.
     */
    void openAbout();

    /**
     *  Gestisce la chiusura del programma.
     */
    void closing();

protected:
    void closeEvent(QCloseEvent * closeEvent);

private:
    MainWindow * mainwindow;
    int dx;
    int dy;
    int pattern;
    ClosingAlert * closingalert;
    About * about;
    QMenu * file;
#ifdef DEBUG_MODE
    Debug * debug;
#endif

    
};

#endif // STARTER_H
