#ifndef CALIBRATIONTHREAD_HPP_
#define CALIBRATIONTHREAD_HPP_

#include <QtCore>
#include "video/ImageSource.hpp"
#include "detection/GazeTracker.hpp"

class Calibration;

class CalibrationThread : public QObject, public TrackerCallback {
    Q_OBJECT

private:
    int width;
    int height;
    ImageSource *camera;
    QMutex *cameraLock;
    vector<Point2f> measurements;
    
    bool calibrate(Calibration & calibration);

public:
    CalibrationThread(int width, int height, ImageSource *camera, QMutex *cameraLock);
    void imageProcessed(Mat& resultImage);
    void imageProcessed(Mat &resultImage, MeasureResult &result, Point2f &gazeVector);
    void run(void);
    
signals:
    void jsCommand(QString);
    void error(QString);
    void cvImage(cv::Mat);

};
#endif