// Default empty project template
#include <bb/cascades/Application>

#include <QLocale>
#include <QSettings>
#include <QTranslator>
#include "applicationui.hpp"

// include JS Debugger / CS Profiler enabler
// this feature is enabled by default in the debug build only
#include <Qt/qdeclarativedebug.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

using namespace bb::cascades;

QSettings *settings;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    settings = new QSettings("themes");
    QString themeString;
    int id = settings->value("THEME", -1).toInt();
	if (id == 0)
	    themeString = "bright";
	else if (id == 1)
		themeString = "dark";
	else
	    themeString = "default";
	if (settings->value("PRIMARY_COLOUR_INDEX", 0).toInt())
	{
	    themeString += "?primaryColor=0x";
	    themeString += ("00" + QString::number(settings->value("PRIMARY_COLOUR_R", 255).toInt() & 0xFF, 16).toUpper()).right(2);
        themeString += ("00" + QString::number(settings->value("PRIMARY_COLOUR_G", 0).toInt() & 0xFF, 16).toUpper()).right(2);
        themeString += ("00" + QString::number(settings->value("PRIMARY_COLOUR_B", 0).toInt() & 0xFF, 16).toUpper()).right(2);
        if (settings->value("BASE_COLOUR_INDEX", 0).toInt())
        {
            themeString += "&amp;primaryBase=0x";
            themeString += ("00" + QString::number(settings->value("BASE_COLOUR_R", 0).toInt() & 0xFF, 16).toUpper()).right(2);
            themeString += ("00" + QString::number(settings->value("BASE_COLOUR_G", 0).toInt() & 0xFF, 16).toUpper()).right(2);
            themeString += ("00" + QString::number(settings->value("BASE_COLOUR_B", 255).toInt() & 0xFF, 16).toUpper()).right(2);
        }
	}
    setenv("CASCADES_THEME", themeString.toAscii().data(), 1);
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
