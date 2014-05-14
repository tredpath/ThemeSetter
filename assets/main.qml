// Default empty project template
import bb.cascades 1.0

// creates one page with a label
Page {
    titleBar: TitleBar {
        title: qsTr("Theme Setter")
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }
    ScrollView {
        Container {
            Container {
                Container {
                    leftPadding: 15.0
                    rightPadding: 15.0
                    topPadding: 15.0
                    Label {
                        text: qsTr("Restart the app for colour and theme changes to take effect.")
                        multiline: true
                    }
                }
                Divider {
                }
            }
            Container {
                topPadding: 15.0
                DropDown {
                    title: qsTr("Visual Theme")
                    horizontalAlignment: HorizontalAlignment.Center
                    selectedIndex: _native.themeIndex
                    Option {
                        description: qsTr("Bright")
                    }
                    Option {
                        description: qsTr("Dark")
                    }
                    
                    onSelectedIndexChanged: {
                        _native.themeIndex = selectedIndex
                    }
                }
            }
            Container {
                topPadding: 15.0
                DropDown {
                    id: _primary
                    horizontalAlignment: HorizontalAlignment.Center
                    selectedIndex: _native.primaryColourIndex
                    Option {
                        text: qsTr("Default")
                    }
                    Option {
                        description: qsTr("Custom")
                    }
                    
                    onSelectedIndexChanged: {
                        _native.primaryColourIndex = selectedIndex
                        if (selectedIndex == 0) {
                            primaryRed.value = 255
                            primaryGreen.value = 0
                            primaryBlue.value = 0
                        }
                    }
                    title: qsTr("Primary Colour")
                }
                Container {
                    rightPadding: 15.0
                    leftPadding: 15.0
                    visible: _primary.selectedIndex == 1
                    
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    Container {
                        minWidth: 100
                        minHeight: 215
                        background: Color.create(primaryRed.value / 255.0, primaryGreen.value / 255.0, primaryBlue.value / 255.0)
                    }
                    Container {
                        leftPadding: 15.0
                        Slider {
                            id: primaryRed
                            fromValue: 0
                            toValue: 255
                            value: _native.primaryColourRed
                            onValueChanged: {
                                _native.primaryColourRed = value
                            }
                        }
                        Slider {
                            id: primaryGreen
                            fromValue: 0
                            toValue: 255
                            value: _native.primaryColourGreen
                            onValueChanged: {
                                _native.primaryColourGreen = value
                            }
                        }
                        Slider {
                            id: primaryBlue
                            fromValue: 0
                            toValue: 255
                            value: _native.primaryColourBlue
                            onValueChanged: {
                                _native.primaryColourBlue = value
                            }
                        }
                    }
                }
            }
            Container {
                topPadding: 15.0
                visible: _primary.selectedIndex == 1
                DropDown {
                    id: _base
                    horizontalAlignment: HorizontalAlignment.Center
                    selectedIndex: _native.baseColourIndex
                    Option {
                        text: qsTr("Default")
                    }
                    Option {
                        description: qsTr("Custom")
                    }
                    
                    onSelectedIndexChanged: {
                        _native.baseColourIndex = selectedIndex
                        if (selectedIndex == 0) {
                            baseRed.value = 0
                            baseGreen.value = 0
                            baseBlue.value = 255
                        }
                    }
                    title: qsTr("Primary Base Colour")
                }
                Container {
                    rightPadding: 15.0
                    leftPadding: 15.0
                    visible: _base.selectedIndex == 1
                    
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    Container {
                        minWidth: 100
                        minHeight: 215
                        background: Color.create(baseRed.value / 255.0, baseGreen.value / 255.0, baseBlue.value / 255.0)
                    }
                    Container {
                        leftPadding: 15.0
                        Slider {
                            id: baseRed
                            fromValue: 0
                            toValue: 255
                            value: _native.baseColourRed
                            onValueChanged: {
                                _native.baseColourRed = value
                            }
                        }
                        Slider {
                            id: baseGreen
                            fromValue: 0
                            toValue: 255
                            value: _native.baseColourGreen
                            onValueChanged: {
                                _native.baseColourGreen = value
                            }
                        }
                        Slider {
                            id: baseBlue
                            fromValue: 0
                            toValue: 255
                            value: _native.baseColourBlue
                            onValueChanged: {
                                _native.baseColourBlue = value
                            }
                        }
                    }
                }
            }
        }
    }
}

