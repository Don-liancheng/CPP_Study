#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainScene.h"
#include <QPushButton.h>
#include <QAction.h>
#include <QPainter.h>
#include <QPixmap.h>
#include "MyPushButton.h"
#include "chooselevelsene.h"
#include <QTimer>
#include <QMenu>
#include <QMenuBar>
#include "PlayScene.h"
#include <QSoundEffect>

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //��д��ͼ�¼���������ͼ
    void paintEvent(QPaintEvent *);

    //�����´���
    chooselevelsene* chooseScene = new chooselevelsene(this);

private:
    Ui::MainSceneClass ui;
};
