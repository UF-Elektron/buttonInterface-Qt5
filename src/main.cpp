#include "mainwindow.h"
#include <QApplication>

#define USE_LISA_CODE

#ifdef USE_LISA_CODE
#include "../../lisa_design/UIrework/src/main.h"
#include "../../lisa_design/UIrework/src/app_kplus.h"
#include "../../lisa_design/UIrework/src/ui.h"
#include "../../lisa_design/UIrework/src/buttonHandler.h"
#include "../../lisa_design/UIrework/src/binding.h"
#include "../../lisa_design/UIrework/src/oku.h"
#include "../../lisa_design/UIrework/src/registerFunctions.h"
#endif

void ProcessKplusRxFrame(int messageType);

int main(int argc, char *argv[])
{
#ifdef USE_LISA_CODE
    setbuf(stdout, NULL); /* Disable buffering for stdout to print from printf directly to console */

    std::clog << "Start of main: rework UI\n"
                 "----------------------------------------------\n\n";

    /* Initialize UI:
     * Set if C-Block sits on a Nebenstelle or on a Hauptstelle
     * Define the behavior of the buttons */
    UI::getInstance().init(false, ButtonTypes::localButton, ButtonTypes::localButton, ButtonTypes::sceneButton, ButtonTypes::sceneButton);
#endif

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#ifdef USE_LISA_CODE
void timerTick()
{
    UI::getInstance().timeoutTicks();
}

void buttonWrapper(int button, int step)
{
    UI::getInstance().test_buttonPress(button, step);
}

void magnetWrapper(int step)
{
    UI::getInstance().test_magnetPress(step);
}

void printLEDs(void)
{
    UI::getInstance().test_printLEDs();
}

void ProcessKplusRxFrame(int messageType)
{
    int readData;
    const int writeData = 42;

    switch (messageType) {

    /* Binding cases */
    case MTP_Event:
        callBinding();
        break;
    case MTP_STATUS:
        callBinding();
        break;
    case MTP_ADDM:
        callBinding();
        break;
    case MTP_REMM:
        callBinding();
        break;
    case MTP_SCNS:
        callBinding();
        break;
    case MTP_SENSOREVENT:
        callBinding();
        break;
    case MTP_REQSTATUS:
        callBinding();
        break;

    /* MTPs for UI (change mode, visualization, etc.) */
    case MTP_BINDINGMODE:
        /* if Mode == 0 : Normal/Configuration Mode */
        /* if Mode == 1 : Installation/Binding Mode */
        UI::getInstance().enterBindingMode(true);
        break;
    case MTP_TIMINGSYNC:
        UI::getInstance().receivedSync();
        break;
    case MTP_RAINBW:
        UI::getInstance().rainbowComissioning();
        break;
    case MTP_PING:
        UI::getInstance().receivedPing();
        break;
    case MTP_SMARTVIZ:  /* Enter SMARTVIZ mode */
        break;
    case (MTP_SMARTVIZ | MTP_ANSWER):   /* A Smart Button was pressed in the system: exit SMARTVIZ mode */
        break;

    /* register read/write MTPs */
    case MTP_REQECHO:
        requestEcho();
        break;
    case MTP_DSCVRY:
        discovery();
        break;
    case MTP_STARTUP:
        startupMessage();
        break;
    case MTP_W_REG_A:
        registerWrite(0, &writeData);
        break;
    case MTP_R_REG_A:
        registerRead(0, &readData);
        break;
    case (MTP_R_REG_A | MTP_ANSWER):
        registerRead(0, &readData);
        break;
    case MTP_W_REG_C:
        registerWrite(0, &writeData);
        break;
    case MTP_R_REG_C:
        registerRead(0, &readData);
        break;
    case (MTP_R_REG_C | MTP_ANSWER):
        registerRead(0, &readData);
        break;

    /* upgrade (OKU) MTPs */
    case MTP_OKUSTATUS:
        okuStatus();
        break;
    case MTP_OKUPREPARE:
        okuPrepare();
        break;
    case MTP_OKUSENDFW:
        okusSendFw();
        break;
    case MTP_OKUDOUPRD:
        okuDoUpgrade();
        break;

    /* warnings */
    case MTP_WARNMSG:
        /* ToDo: Call a UI function? */
        std::cout << "MTP_WARNMSG\n";
        break;
    default:
        std::cout << "Warning: This MTP is not handled!\n";
        break;
    }
}
#endif
