// Default empty project template
#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <QSettings>

#include <stdio.h>

namespace bb { namespace cascades { class Application; }}

extern QSettings *settings;

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int themeIndex READ themeIndex WRITE themeIndex NOTIFY dummySignal)
    Q_PROPERTY(int primaryColourIndex READ primaryColourIndex WRITE primaryColourIndex NOTIFY dummySignal)
    Q_PROPERTY(int primaryColourRed READ primaryColourRed WRITE primaryColourRed NOTIFY dummySignal)
    Q_PROPERTY(int primaryColourGreen READ primaryColourGreen WRITE primaryColourGreen NOTIFY dummySignal)
    Q_PROPERTY(int primaryColourBlue READ primaryColourBlue WRITE primaryColourBlue NOTIFY dummySignal)
    Q_PROPERTY(int baseColourIndex READ baseColourIndex WRITE baseColourIndex NOTIFY dummySignal)
    Q_PROPERTY(int baseColourRed READ baseColourRed WRITE baseColourRed NOTIFY dummySignal)
    Q_PROPERTY(int baseColourGreen READ baseColourGreen WRITE baseColourGreen NOTIFY dummySignal)
    Q_PROPERTY(int baseColourBlue READ baseColourBlue WRITE baseColourBlue NOTIFY dummySignal)

public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI();

signals:
    void dummySignal();

protected:
    inline int themeIndex() const { return settings->value("THEME", 0).toInt(); }
    inline int primaryColourIndex() const { return settings->value("PRIMARY_COLOUR_INDEX", 0).toInt(); }
    inline int primaryColourRed() const { return settings->value("PRIMARY_COLOUR_R", 255).toInt(); }
    inline int primaryColourGreen() const { return settings->value("PRIMARY_COLOUR_G", 0).toInt(); }
    inline int primaryColourBlue() const { return settings->value("PRIMARY_COLOUR_B", 0).toInt(); }
    inline int baseColourIndex() const { return settings->value("BASE_COLOUR_INDEX", 0).toInt(); }
    inline int baseColourRed() const { return settings->value("BASE_COLOUR_R", 0).toInt(); }
    inline int baseColourGreen() const { return settings->value("BASE_COLOUR_G", 0).toInt(); }
    inline int baseColourBlue() const { return settings->value("BASE_COLOUR_B", 255).toInt(); }

    inline void themeIndex(int index) { settings->setValue("THEME", index); }
    inline void primaryColourIndex(int index) { settings->setValue("PRIMARY_COLOUR_INDEX", index); }
    inline void primaryColourRed(int value) { settings->setValue("PRIMARY_COLOUR_R", value); }
    inline void primaryColourGreen(int value) { settings->setValue("PRIMARY_COLOUR_G", value); }
    inline void primaryColourBlue(int value) { settings->setValue("PRIMARY_COLOUR_B", value); }
    inline void baseColourIndex(int index) { settings->setValue("BASE_COLOUR_INDEX", index); }
    inline void baseColourRed(int value) { settings->setValue("BASE_COLOUR_R", value); }
    inline void baseColourGreen(int value) { settings->setValue("BASE_COLOUR_G", value); }
    inline void baseColourBlue(int value) { settings->setValue("BASE_COLOUR_B", value); }
};


#endif /* ApplicationUI_HPP_ */
