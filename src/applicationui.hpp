// Default empty project template
#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int themeIndex READ themeIndex WRITE themeIndex)

public:
    enum
    {
    	Bright = 0,
    	Dark = 1
    };

public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() {}

protected:
    inline int themeIndex() { return m_theme; }

    void themeIndex(int index);

private:
    int m_theme;
};


#endif /* ApplicationUI_HPP_ */
