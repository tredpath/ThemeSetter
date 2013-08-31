// Default empty project template
import bb.cascades 1.0

// creates one page with a label
Page {
    titleBar: TitleBar {
        title: qsTr("Theme Setter")
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }
    Container {
        topPadding: 15.0
        Container {
            leftPadding: 15.0
            Label {
                text: qsTr("Default Theme")
                leftMargin: 15.0
            }
        }
        DropDown {
            horizontalAlignment: HorizontalAlignment.Center
            Option {
                description: qsTr("Bright")
            }
            Option {
                description: qsTr("Dark")
            }
            
            onCreationCompleted: {
                selectedIndex = _native.themeIndex
            }
            
            onSelectedIndexChanged: {
                _native.themeIndex = selectedIndex
            }
            title: qsTr("Visual Theme")
        }
        Container {
            leftPadding: 15.0
            rightPadding: 15.0
            Label {
                text: qsTr("Restart the app for the colour theme change to take effect.")
                multiline: true
            }
        }
        Divider {
        }
    }
}

