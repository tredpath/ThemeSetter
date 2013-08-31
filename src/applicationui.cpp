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
	ThemeSupport* themeSupport = app->themeSupport();
	Theme* currentTheme = themeSupport->theme();
	ColorTheme* colorTheme = currentTheme->colorTheme();
	VisualStyle::Type style = colorTheme->style();
	switch (style)
	{
	case VisualStyle::Bright:
		m_theme = Bright;
		break;
	case VisualStyle::Dark:
		m_theme = Dark;
		break;
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

void ApplicationUI::themeIndex(int index)
{
	if (index == m_theme)
		return;
	QFile::remove("data/dark.dat");
	QFile::remove("data/bright.dat");
	if (index == 0)
	{
		QFile file("data/bright.dat");
		file.open(QFile::WriteOnly);
		file.close();
		m_theme = Bright;
	}
	else
	{
		QFile file("data/dark.dat");
		file.open(QFile::WriteOnly);
		file.close();
		m_theme = Dark;
	}
}

