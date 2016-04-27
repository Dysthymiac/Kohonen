#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->graphicsView->setAutoScale(false);
    on_pushButton_clicked();
    running = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    net = KohonenNetwork(ui->spinBox->value(), ui->spinBox_2->value(), 3);
    QImage* img = new QImage(net.cols(),net.rows(),QImage::Format_RGB32);
    ui->graphicsView->setImageObject(img);
    net.initWeights();
    updateImage();
}

void MainWindow::on_pushButton_2_clicked()
{
    net.initWeights();
    updateImage();
}

void MainWindow::on_pushButton_3_clicked()
{
    net.initWeightsGrad();
    updateImage();
}

void MainWindow::updateImage()
{
    for(size_t y = 0; y < net.rows(); ++y)
        for(size_t x = 0; x < net.cols(); ++x)
            ui->graphicsView->getImageObject()->setPixel(x, y, qRgb((int)(net[y][x][0]*255), (int)(net[y][x][1]*255), (int)(net[y][x][2]*255)));
    ui->graphicsView->setImageObject(ui->graphicsView->getImageObject());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(running)
    {
        running = false;
        return;
    }
    running = true;
    std::vector<double> input(3, 0);

    int iterations = ui->itersSpinBox->value();
    double learningRate = ui->speedSpinBox->value();

    for(int i = 1; i <= iterations; ++i)
    {
        for(int j = 0; j < 3; ++j)
            input[j] = (double)rand() / RAND_MAX;
        net.learnStep(i, input, iterations, learningRate);

        if(!running)
            break;
        if(ui->checkBox->isChecked())
        {
            updateImage();
            ui->progressBar->setValue(((double)i / iterations)*100);
            QApplication::processEvents();
        }
    }
    updateImage();
    running = false;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(running)
    {
        running = false;
        return;
    }
    running = true;
    int set = ui->dataSpinBox->value();
    std::vector<std::vector<double> > input(set, std::vector<double>(3, 0));
    for(int i = 0; i < set; ++i)
        for(int j = 0; j < 3; ++j)
            input[i][j] = (double)rand() / RAND_MAX;

    int iterations = ui->itersSpinBox->value();
    double learningRate = ui->speedSpinBox->value();

    for(int i = 1; i <= iterations; ++i)
    {
        net.learnStep(i, input[rand()%set], iterations, learningRate);
        if(!running)
            break;
        if(ui->checkBox->isChecked())
        {
            updateImage();
            ui->progressBar->setValue(((double)i / iterations)*100);
            QApplication::processEvents();
        }
    }
    updateImage();
    running = false;
}
