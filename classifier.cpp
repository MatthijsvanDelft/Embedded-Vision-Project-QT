#include "classifier.h"

/** Classifier
 * @brief Constructor of classifier.
 */
Classifier::Classifier()
{
    carVector.push_back(Car());
}

/** classifyCars()
 * @brief Classifies contours into different cars.
 */
void Classifier::classifyCars()
{
    cv::Mat tmp = cv::Mat::zeros(image->size(), CV_8UC3);

    for(unsigned int i=0; i<contours->size(); i++){

        double contourArea = cv::contourArea(contours->at(i));

        if(contourArea > 300.0 && contourArea < 400.0){/// Minus
            cv::drawContours(tmp , *contours, i, cv::Scalar(255,255,255), 4, 8, *hierarchy, 0, cv::Point());
            cv::threshold(tmp, tmp, 0, 254, cv::THRESH_BINARY);

            carVector.at(0).setImage(&tmp);
            carVector.at(0).setSymbol("Minus");

            //cv::imshow("Car1", *carVector.at(0).getImage());
            //cv::moveWindow("Video stream", 300, 300);
            //std::cout << "Coordinates " << carVector.at(0).getCoordinates() << std::endl;
        }/*
        else if(contourArea > 100.0 && contourArea < 130.0){/// Plus
            carVector.push_back(Car());
            cv::drawContours(tmp , *contours, i, cv::Scalar(255,255,255), 2, 8, *hierarchy, 0, cv::Point());
            carVector.at(1).setImage(&tmp);
            carVector.at(1).setSymbol("Plus");
            //cv::imshow("Car2", *carVector.at(1).getImage());
        }*/
    }
}

/** setImage()
 * @brief Sets image as size reference.
 * @param pointer to cv::Mat image.
 */
void Classifier::setImage(cv::Mat *im)
{
    image = im;
}

/** setContours()
 * @param Sets 2D vector of contours produced from function drawContours from class DIP.
 */
void Classifier::setContours(std::vector<std::vector<cv::Point>> *cont)
{
    contours = cont;
}

/** setHierarchy()
 * @param Sets Vector ? produced from function drawContours from class DIP.
 */
void Classifier::setHierarchy(std::vector<cv::Vec4i> *hier)
{
    hierarchy = hier;
}

/** getCars()
 * @return Returns pointer to vector of cars.
 */
std::vector<Car> *Classifier::getCars(){

    return &carVector;
}
