#include "stylehelper.h"


QString stylehelper::getButtonAddStyle()
{
    return "QPushButton{"
            "background:none;"
            "background-image:url(:/resources/icon_plus(white).png);"
            "background-repeat:no repeat;"
            "background-position:center center;"
            "border:none;"
            "border-radius:7px;"
            "color:#FAEBD7;"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
           "}"

            "QToolTip{"
            "border:none;"
            "border:2px solid black;"
            "border-radius:5px;"
            "background-color:#888888;"
            "}"

           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"
            "}";
}

QString stylehelper::getButtonSaveStyle()
{
    return "QPushButton{"
            "background:none;"
            "background-image:url(:/resources/icon_save.png);"
            "background-repeat:no repeat;"
            "background-position:center center;"
            "border:none;"
            "border-radius:7px;"
            "color:#FAEBD7;"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
            "}"

           "QToolTip{"
           "border:none;"
           "border:2px solid black;"
           "border-radius:5px;"
           "background-color:#888888;"
           "}"

           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"
           "}";
}

QString stylehelper::getButtonDeleteLineStyle()
{
    return "QPushButton{"
            "background:none;"
            "border:none;"
            "border-radius:7px;"
             "color:#FAEBD7;"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
           "}"

           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"
           "}";
}

QString stylehelper::getButtonDeleteAllStyle()
{
    return "QPushButton{"
            "background:none;"
            "border:none;"
            "border-radius:7px;"
            "color:#FAEBD7;"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
            "}"

            "QPushButton::hover{"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"


           "}";

}

QString stylehelper::getButtonCloseStyle()
{
    return "QPushButton{"
            "background:none;"
            "border:none;"
            "border-radius:7px;"
             "color:#FAEBD7;"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(33, 31, 30, 255));"

           "}"
           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.800818, stop:0 rgba(0, 0, 0, 255), stop:0.995 rgba(176, 15, 44, 255));"
            "}";
}

QString stylehelper::getMenuStyle()
{
    return "QMenu{"
            "background:none;"
             "margin: 5px;"
            "color:#FAEBD7;"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
            "}"

            "QMenu::item {"
                /* устанавливаем фон пункта меню. установите его во что-нибудь непрозрачное
                    если вы хотите чтобы цвет меню отличался от цвета пункта меню */
                "border: 1px solid transparent;"
            "margin: 5px;"
            "}"

            "QMenu::item:selected {" /* когда пользователь выбирает пункт с помощью мыши или клавиатуры */
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"
             "border-color: darkblue;"
             "}"

    "QMenu::separator {"
        "height: 10px;"
        "background: lightblue;"
        "margin-left: 10px;"
        "margin-right: 5px;"
    "}";

}

QString stylehelper::getMenuBarStyle()
{
    return   "QMenuBar {"
//            "background-color:00697f;"
        "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 lightgray, stop:1 darkgray);"
    "}"

   " QMenuBar::item {"
        "spacing: 3px;" /* интервал между пунктами меню */
        "padding: 1px 4px;"
        "background: transparent;"
        "border-radius: 4px;"
    "}"

    "QMenuBar::item:selected {" /* когда выделено с помощью мыши или клавиатуры */
        "background: #a8a8a8;"
    "}"

    "QMenuBar::item:pressed {"
        "background: #888888;"
    "}";

}

QString stylehelper::getTableViewStyle()
{
    return "QTableView {"
        "selection-background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:0, y2:0.29, stop:0 rgba(146, 0, 137, 255), stop:1 rgba(18, 153, 211, 255));"
            "background-color:#888888;"
            "background-image:url(:/resources/fon_table_view.jpg);"
            "color:#FAEBD7;"
            "border:7px solid #c3c3c3;"
            "border-radius:5px;"
           "}"
            "QTableView QTableCornerButton::section{"
            "background-color:#006a83;"
            "}"


            ;
}

QString stylehelper::getGorizHeaderTableStyle()
{
    return " QHeaderView#gorizHeader::section{"
            "background-color:#006a83;"
        "}";

}

QString stylehelper::getVertHeaderTableStyle()
{
    return " QHeaderView#vertHeader::section{"
            "background-color:#006a83;"
           "}";
}

QString stylehelper::getButtonDialogCloseStyle()
{
    return "QPushButton{"
            "background:none;"
            "border:none;"
            "border-radius:7px;"
           "background-image:url(:/resources/icon_cancel.png);"
           "background-repeat:no repeat;"
           "background-position:right center;"
            "color:#FAEBD7;"
            "text-align:left;"
            "padding-left:10px;"
            "padding-right:10px;"
            "font-size:25px;"
            "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(33, 31, 30, 255));"

           "}"
           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.800818, stop:0 rgba(0, 0, 0, 255), stop:0.995 rgba(176, 15, 44, 255));"
           "}";
}

QString stylehelper::getButtonDialogApplyStyle()
{
    return "QPushButton{"
            "background:none;"
            "background-image:url(:/resources/icon_ok.png);"
            "background-repeat:no repeat;"
            "background-position:right center;"
             "border:none;"
             "border-radius:7px;"
            "text-align:left;"
           "padding-left:10px;"
           "padding-right:10px;"
            "font-size:25px;"
            "color:#FAEBD7;"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(139, 0, 255, 255), stop:1 rgba(0, 116, 255, 254));"
           "}"


           "QPushButton::hover{"
           "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.943, stop:0 rgba(0, 0, 124, 255), stop:1 rgba(170, 110, 255, 255));"
           "}";
}

QString stylehelper::getLableDialogStyle()
{
    return "QLabel {"
            "font-size:15px;"
            "margin:20px,20px,20px,20px;"
            "}";
}
