// Default empty project template
#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ThemeSupport>
#include <bb/cascades/Theme>
#include <bb/cascades/ColorTheme>
#include <bb/cascades/VisualStyle>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app)
	: QObject(app)
{
    if (settings->value("THEME", -1).toInt() < 0)
    {
        ThemeSupport* themeSupport = app->themeSupport();
        Theme* currentTheme = themeSupport->theme();
        ColorTheme* colorTheme = currentTheme->colorTheme();
        VisualStyle::Type style = colorTheme->style();
        switch (style)
        {
        case VisualStyle::Bright:
            settings->setValue("THEME", 0);
            break;
        case VisualStyle::Dark:
            settings->setValue("THEME", 1);
            break;
        }
    }
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("_native", this);

    // create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
}

ApplicationUI::~ApplicationUI()
{
}

