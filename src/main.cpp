// Default empty project template
#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

// include JS Debugger / CS Profiler enabler
// this feature is enabled by default in the debug build only
#include <Qt/qdeclarativedebug.h>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
	struct stat buf;
	if (!stat("data/bright.dat", &buf))
		setenv("CASCADES_THEME", "bright", 1);
	else if (!stat("data/dark.dat", &buf))
		setenv("CASCADES_THEME", "dark", 1);
    // this is where the server is started etc
    Application app(argc, argv);
    app.setMenuEnabled(false);

    // localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "ThemeSetter_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }

    new ApplicationUI(&app);

    // we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}
