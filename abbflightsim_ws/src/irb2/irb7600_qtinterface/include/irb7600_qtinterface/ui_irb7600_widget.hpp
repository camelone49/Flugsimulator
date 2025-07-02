/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRB7600_WIDGET_H
#define UI_IRB7600_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightSimControl_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *HeaderLabel;
    QLabel *ImpressumLabel;
    QGroupBox *SetJointStatesBox;
    QLineEdit *joint1_rad;
    QLineEdit *joint2_rad;
    QLineEdit *joint3_rad;
    QLineEdit *joint4_rad;
    QLineEdit *joint5_rad;
    QLineEdit *joint6_rad;
    QLabel *Joint1_label;
    QLabel *joint2_label;
    QLabel *joint3_label;
    QLabel *joint4_label;
    QLabel *joint5_label;
    QLabel *joint6_label;
    QPushButton *publishradpos;
    QLabel *joint1_desired_label;
    QLabel *joint2_desired_label;
    QLabel *joint3_desired_label;
    QLabel *joint4_desired_label;
    QLabel *joint5_desired_label;
    QLabel *joint6_acutal_label;
    QLabel *joint1_actual_label;
    QLabel *joint2_actual_label;
    QLabel *joint3_actual_label;
    QLabel *joint4_actual_label;
    QLabel *joint5_actual_label;
    QLabel *joint6_desired_label;
    QLabel *desiredandactualheader_label;
    QGroupBox *SetCoordinatesBox;
    QLineEdit *xcoord_line;
    QLineEdit *ycoord_line;
    QLineEdit *zcoord_line;
    QLineEdit *oxcoord_line;
    QLineEdit *oycoord_line;
    QLineEdit *ozcoord_line;
    QLabel *x_label;
    QLabel *y_label;
    QLabel *z_label;
    QLabel *ox_label;
    QLabel *oy_label;
    QLabel *oz_label;
    QPushButton *publishcoordinates_button;
    QGroupBox *groupBox_3;
    QPushButton *randompos_pushbutton;
    QPushButton *centerpos_pushbutton;
    QGroupBox *ControllerStatusBox;
    QLabel *controllermanager_label;
    QLabel *controller_list_status;
    QLabel *hwinterface_label;
    QLabel *controller_list_label;
    QLabel *hwinterface_status;
    QLabel *controller_manager_status;
    QLabel *trajectory_label;
    QLabel *trajectory_status;
    QLabel *githublink_label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FlightSimControl_MainWindow)
    {
        if (FlightSimControl_MainWindow->objectName().isEmpty())
            FlightSimControl_MainWindow->setObjectName(QString::fromUtf8("FlightSimControl_MainWindow"));
        FlightSimControl_MainWindow->resize(480, 632);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FlightSimControl_MainWindow->sizePolicy().hasHeightForWidth());
        FlightSimControl_MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        FlightSimControl_MainWindow->setFont(font);
        centralwidget = new QWidget(FlightSimControl_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        HeaderLabel = new QLabel(centralwidget);
        HeaderLabel->setObjectName(QString::fromUtf8("HeaderLabel"));
        HeaderLabel->setGeometry(QRect(10, 9, 450, 23));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(HeaderLabel->sizePolicy().hasHeightForWidth());
        HeaderLabel->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        HeaderLabel->setFont(font1);
        ImpressumLabel = new QLabel(centralwidget);
        ImpressumLabel->setObjectName(QString::fromUtf8("ImpressumLabel"));
        ImpressumLabel->setGeometry(QRect(10, 590, 301, 20));
        QFont font2;
        font2.setPointSize(8);
        ImpressumLabel->setFont(font2);
        SetJointStatesBox = new QGroupBox(centralwidget);
        SetJointStatesBox->setObjectName(QString::fromUtf8("SetJointStatesBox"));
        SetJointStatesBox->setGeometry(QRect(10, 40, 461, 211));
        QFont font3;
        font3.setPointSize(11);
        SetJointStatesBox->setFont(font3);
        joint1_rad = new QLineEdit(SetJointStatesBox);
        joint1_rad->setObjectName(QString::fromUtf8("joint1_rad"));
        joint1_rad->setGeometry(QRect(20, 50, 61, 23));
        joint2_rad = new QLineEdit(SetJointStatesBox);
        joint2_rad->setObjectName(QString::fromUtf8("joint2_rad"));
        joint2_rad->setGeometry(QRect(90, 50, 61, 23));
        joint3_rad = new QLineEdit(SetJointStatesBox);
        joint3_rad->setObjectName(QString::fromUtf8("joint3_rad"));
        joint3_rad->setGeometry(QRect(160, 50, 61, 23));
        joint4_rad = new QLineEdit(SetJointStatesBox);
        joint4_rad->setObjectName(QString::fromUtf8("joint4_rad"));
        joint4_rad->setGeometry(QRect(230, 50, 61, 23));
        joint5_rad = new QLineEdit(SetJointStatesBox);
        joint5_rad->setObjectName(QString::fromUtf8("joint5_rad"));
        joint5_rad->setGeometry(QRect(300, 50, 61, 23));
        joint6_rad = new QLineEdit(SetJointStatesBox);
        joint6_rad->setObjectName(QString::fromUtf8("joint6_rad"));
        joint6_rad->setGeometry(QRect(370, 50, 61, 23));
        Joint1_label = new QLabel(SetJointStatesBox);
        Joint1_label->setObjectName(QString::fromUtf8("Joint1_label"));
        Joint1_label->setGeometry(QRect(20, 30, 57, 15));
        QFont font4;
        font4.setPointSize(9);
        Joint1_label->setFont(font4);
        joint2_label = new QLabel(SetJointStatesBox);
        joint2_label->setObjectName(QString::fromUtf8("joint2_label"));
        joint2_label->setGeometry(QRect(90, 30, 57, 15));
        joint2_label->setFont(font4);
        joint3_label = new QLabel(SetJointStatesBox);
        joint3_label->setObjectName(QString::fromUtf8("joint3_label"));
        joint3_label->setGeometry(QRect(160, 30, 57, 15));
        joint3_label->setFont(font4);
        joint4_label = new QLabel(SetJointStatesBox);
        joint4_label->setObjectName(QString::fromUtf8("joint4_label"));
        joint4_label->setGeometry(QRect(230, 30, 57, 15));
        joint4_label->setFont(font4);
        joint5_label = new QLabel(SetJointStatesBox);
        joint5_label->setObjectName(QString::fromUtf8("joint5_label"));
        joint5_label->setGeometry(QRect(300, 30, 57, 15));
        joint5_label->setFont(font4);
        joint6_label = new QLabel(SetJointStatesBox);
        joint6_label->setObjectName(QString::fromUtf8("joint6_label"));
        joint6_label->setGeometry(QRect(370, 30, 57, 15));
        joint6_label->setFont(font4);
        publishradpos = new QPushButton(SetJointStatesBox);
        publishradpos->setObjectName(QString::fromUtf8("publishradpos"));
        publishradpos->setGeometry(QRect(19, 80, 411, 23));
        joint1_desired_label = new QLabel(SetJointStatesBox);
        joint1_desired_label->setObjectName(QString::fromUtf8("joint1_desired_label"));
        joint1_desired_label->setGeometry(QRect(20, 140, 57, 31));
        joint1_desired_label->setFont(font4);
        joint2_desired_label = new QLabel(SetJointStatesBox);
        joint2_desired_label->setObjectName(QString::fromUtf8("joint2_desired_label"));
        joint2_desired_label->setGeometry(QRect(90, 140, 57, 31));
        joint2_desired_label->setFont(font4);
        joint3_desired_label = new QLabel(SetJointStatesBox);
        joint3_desired_label->setObjectName(QString::fromUtf8("joint3_desired_label"));
        joint3_desired_label->setGeometry(QRect(160, 140, 57, 31));
        joint3_desired_label->setFont(font4);
        joint4_desired_label = new QLabel(SetJointStatesBox);
        joint4_desired_label->setObjectName(QString::fromUtf8("joint4_desired_label"));
        joint4_desired_label->setGeometry(QRect(230, 140, 57, 31));
        joint4_desired_label->setFont(font4);
        joint5_desired_label = new QLabel(SetJointStatesBox);
        joint5_desired_label->setObjectName(QString::fromUtf8("joint5_desired_label"));
        joint5_desired_label->setGeometry(QRect(300, 140, 57, 31));
        joint5_desired_label->setFont(font4);
        joint6_acutal_label = new QLabel(SetJointStatesBox);
        joint6_acutal_label->setObjectName(QString::fromUtf8("joint6_acutal_label"));
        joint6_acutal_label->setGeometry(QRect(370, 170, 57, 31));
        joint6_acutal_label->setFont(font4);
        joint1_actual_label = new QLabel(SetJointStatesBox);
        joint1_actual_label->setObjectName(QString::fromUtf8("joint1_actual_label"));
        joint1_actual_label->setGeometry(QRect(20, 170, 57, 31));
        joint1_actual_label->setFont(font4);
        joint2_actual_label = new QLabel(SetJointStatesBox);
        joint2_actual_label->setObjectName(QString::fromUtf8("joint2_actual_label"));
        joint2_actual_label->setGeometry(QRect(90, 170, 57, 31));
        joint2_actual_label->setFont(font4);
        joint3_actual_label = new QLabel(SetJointStatesBox);
        joint3_actual_label->setObjectName(QString::fromUtf8("joint3_actual_label"));
        joint3_actual_label->setGeometry(QRect(160, 170, 57, 31));
        joint3_actual_label->setFont(font4);
        joint4_actual_label = new QLabel(SetJointStatesBox);
        joint4_actual_label->setObjectName(QString::fromUtf8("joint4_actual_label"));
        joint4_actual_label->setGeometry(QRect(230, 170, 57, 31));
        joint4_actual_label->setFont(font4);
        joint5_actual_label = new QLabel(SetJointStatesBox);
        joint5_actual_label->setObjectName(QString::fromUtf8("joint5_actual_label"));
        joint5_actual_label->setGeometry(QRect(300, 170, 57, 31));
        joint5_actual_label->setFont(font4);
        joint6_desired_label = new QLabel(SetJointStatesBox);
        joint6_desired_label->setObjectName(QString::fromUtf8("joint6_desired_label"));
        joint6_desired_label->setGeometry(QRect(370, 140, 57, 31));
        joint6_desired_label->setFont(font4);
        desiredandactualheader_label = new QLabel(SetJointStatesBox);
        desiredandactualheader_label->setObjectName(QString::fromUtf8("desiredandactualheader_label"));
        desiredandactualheader_label->setGeometry(QRect(20, 110, 401, 31));
        QFont font5;
        font5.setPointSize(10);
        desiredandactualheader_label->setFont(font5);
        desiredandactualheader_label->setAlignment(Qt::AlignCenter);
        SetCoordinatesBox = new QGroupBox(centralwidget);
        SetCoordinatesBox->setObjectName(QString::fromUtf8("SetCoordinatesBox"));
        SetCoordinatesBox->setGeometry(QRect(10, 260, 461, 111));
        SetCoordinatesBox->setFont(font3);
        xcoord_line = new QLineEdit(SetCoordinatesBox);
        xcoord_line->setObjectName(QString::fromUtf8("xcoord_line"));
        xcoord_line->setGeometry(QRect(20, 50, 61, 23));
        ycoord_line = new QLineEdit(SetCoordinatesBox);
        ycoord_line->setObjectName(QString::fromUtf8("ycoord_line"));
        ycoord_line->setGeometry(QRect(90, 50, 61, 23));
        zcoord_line = new QLineEdit(SetCoordinatesBox);
        zcoord_line->setObjectName(QString::fromUtf8("zcoord_line"));
        zcoord_line->setGeometry(QRect(160, 50, 61, 23));
        oxcoord_line = new QLineEdit(SetCoordinatesBox);
        oxcoord_line->setObjectName(QString::fromUtf8("oxcoord_line"));
        oxcoord_line->setGeometry(QRect(230, 50, 61, 23));
        oycoord_line = new QLineEdit(SetCoordinatesBox);
        oycoord_line->setObjectName(QString::fromUtf8("oycoord_line"));
        oycoord_line->setGeometry(QRect(300, 50, 61, 23));
        ozcoord_line = new QLineEdit(SetCoordinatesBox);
        ozcoord_line->setObjectName(QString::fromUtf8("ozcoord_line"));
        ozcoord_line->setGeometry(QRect(370, 50, 61, 23));
        x_label = new QLabel(SetCoordinatesBox);
        x_label->setObjectName(QString::fromUtf8("x_label"));
        x_label->setGeometry(QRect(20, 30, 57, 15));
        x_label->setFont(font4);
        y_label = new QLabel(SetCoordinatesBox);
        y_label->setObjectName(QString::fromUtf8("y_label"));
        y_label->setGeometry(QRect(90, 30, 57, 15));
        y_label->setFont(font4);
        z_label = new QLabel(SetCoordinatesBox);
        z_label->setObjectName(QString::fromUtf8("z_label"));
        z_label->setGeometry(QRect(160, 30, 57, 15));
        z_label->setFont(font4);
        ox_label = new QLabel(SetCoordinatesBox);
        ox_label->setObjectName(QString::fromUtf8("ox_label"));
        ox_label->setGeometry(QRect(230, 30, 57, 15));
        ox_label->setFont(font4);
        oy_label = new QLabel(SetCoordinatesBox);
        oy_label->setObjectName(QString::fromUtf8("oy_label"));
        oy_label->setGeometry(QRect(300, 30, 57, 15));
        oy_label->setFont(font4);
        oz_label = new QLabel(SetCoordinatesBox);
        oz_label->setObjectName(QString::fromUtf8("oz_label"));
        oz_label->setGeometry(QRect(370, 30, 57, 15));
        oz_label->setFont(font4);
        publishcoordinates_button = new QPushButton(SetCoordinatesBox);
        publishcoordinates_button->setObjectName(QString::fromUtf8("publishcoordinates_button"));
        publishcoordinates_button->setGeometry(QRect(20, 80, 411, 23));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 380, 461, 61));
        randompos_pushbutton = new QPushButton(groupBox_3);
        randompos_pushbutton->setObjectName(QString::fromUtf8("randompos_pushbutton"));
        randompos_pushbutton->setGeometry(QRect(10, 30, 221, 23));
        centerpos_pushbutton = new QPushButton(groupBox_3);
        centerpos_pushbutton->setObjectName(QString::fromUtf8("centerpos_pushbutton"));
        centerpos_pushbutton->setGeometry(QRect(230, 30, 221, 23));
        ControllerStatusBox = new QGroupBox(centralwidget);
        ControllerStatusBox->setObjectName(QString::fromUtf8("ControllerStatusBox"));
        ControllerStatusBox->setGeometry(QRect(9, 450, 461, 121));
        controllermanager_label = new QLabel(ControllerStatusBox);
        controllermanager_label->setObjectName(QString::fromUtf8("controllermanager_label"));
        controllermanager_label->setGeometry(QRect(10, 30, 141, 21));
        controllermanager_label->setFont(font5);
        controller_list_status = new QLabel(ControllerStatusBox);
        controller_list_status->setObjectName(QString::fromUtf8("controller_list_status"));
        controller_list_status->setGeometry(QRect(150, 50, 301, 21));
        controller_list_status->setFont(font5);
        hwinterface_label = new QLabel(ControllerStatusBox);
        hwinterface_label->setObjectName(QString::fromUtf8("hwinterface_label"));
        hwinterface_label->setGeometry(QRect(10, 70, 181, 21));
        hwinterface_label->setFont(font5);
        controller_list_label = new QLabel(ControllerStatusBox);
        controller_list_label->setObjectName(QString::fromUtf8("controller_list_label"));
        controller_list_label->setGeometry(QRect(10, 50, 141, 21));
        controller_list_label->setFont(font5);
        hwinterface_status = new QLabel(ControllerStatusBox);
        hwinterface_status->setObjectName(QString::fromUtf8("hwinterface_status"));
        hwinterface_status->setGeometry(QRect(190, 70, 301, 21));
        hwinterface_status->setFont(font5);
        controller_manager_status = new QLabel(ControllerStatusBox);
        controller_manager_status->setObjectName(QString::fromUtf8("controller_manager_status"));
        controller_manager_status->setGeometry(QRect(150, 30, 161, 21));
        controller_manager_status->setFont(font5);
        trajectory_label = new QLabel(ControllerStatusBox);
        trajectory_label->setObjectName(QString::fromUtf8("trajectory_label"));
        trajectory_label->setGeometry(QRect(10, 90, 151, 21));
        trajectory_label->setFont(font5);
        trajectory_status = new QLabel(ControllerStatusBox);
        trajectory_status->setObjectName(QString::fromUtf8("trajectory_status"));
        trajectory_status->setGeometry(QRect(160, 90, 151, 21));
        trajectory_status->setFont(font5);
        githublink_label = new QLabel(centralwidget);
        githublink_label->setObjectName(QString::fromUtf8("githublink_label"));
        githublink_label->setGeometry(QRect(10, 570, 271, 20));
        githublink_label->setFont(font2);
        FlightSimControl_MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FlightSimControl_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FlightSimControl_MainWindow->setStatusBar(statusbar);

        retranslateUi(FlightSimControl_MainWindow);

        QMetaObject::connectSlotsByName(FlightSimControl_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FlightSimControl_MainWindow)
    {
        FlightSimControl_MainWindow->setWindowTitle(QCoreApplication::translate("FlightSimControl_MainWindow", "MainWindow", nullptr));
        HeaderLabel->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "6 DOF Robot Flight Simulator Control Hub", nullptr));
        ImpressumLabel->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "By Hisham Farid, June 2025, hishamfarid04gmail.com", nullptr));
        SetJointStatesBox->setTitle(QCoreApplication::translate("FlightSimControl_MainWindow", "Set and Monitor Joint Positions", nullptr));
        joint1_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        joint2_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        joint3_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        joint4_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        joint5_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        joint6_rad->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        Joint1_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 1", nullptr));
        joint2_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 2", nullptr));
        joint3_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 3", nullptr));
        joint4_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 4", nullptr));
        joint5_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 5", nullptr));
        joint6_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Joint 6", nullptr));
        publishradpos->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Publish Positions", nullptr));
        joint1_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint2_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint3_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint4_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint5_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint6_acutal_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint1_actual_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint2_actual_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint3_actual_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint4_actual_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint5_actual_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        joint6_desired_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "TextLabel", nullptr));
        desiredandactualheader_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Desired (Upper Row) and Actual Positions (Bottom Row)", nullptr));
        SetCoordinatesBox->setTitle(QCoreApplication::translate("FlightSimControl_MainWindow", "Set Desired Coordinates and Orientation", nullptr));
        xcoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        ycoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        zcoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        oxcoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        oycoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        ozcoord_line->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "0.0", nullptr));
        x_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "    X", nullptr));
        y_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "    Y", nullptr));
        z_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "   Z", nullptr));
        ox_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "   OX", nullptr));
        oy_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "   OY", nullptr));
        oz_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "   OZ", nullptr));
        publishcoordinates_button->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Publish Coordinates", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FlightSimControl_MainWindow", "Preset Positions", nullptr));
        randompos_pushbutton->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Random Positions", nullptr));
        centerpos_pushbutton->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Center Position", nullptr));
        ControllerStatusBox->setTitle(QCoreApplication::translate("FlightSimControl_MainWindow", "Controller Status", nullptr));
        controllermanager_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Controller Manager:", nullptr));
        controller_list_status->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "WAITING FOR LIST...", nullptr));
        hwinterface_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Hardware Interface State:", nullptr));
        controller_list_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Controller List:", nullptr));
        hwinterface_status->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "WAITING FOR STATUS...", nullptr));
        controller_manager_status->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "WAITING FOR STATUS...", nullptr));
        trajectory_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "Trajectory Execution: ", nullptr));
        trajectory_status->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "WAITING FOR STATUS...", nullptr));
        githublink_label->setText(QCoreApplication::translate("FlightSimControl_MainWindow", "https://github.com/camelone49/Flugsimulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightSimControl_MainWindow: public Ui_FlightSimControl_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRB7600_WIDGET_H
