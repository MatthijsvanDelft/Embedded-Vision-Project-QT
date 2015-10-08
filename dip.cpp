#include "dip.h"

/** DIP()
 * Constructor of DIP
 */

DIP::DIP()
{

}

/** makeGrayscale()
 * Creates binary image fom normal images.
 */
void DIP::makeGrayscale(cv::Mat *srcImage)
{
    ///Convert the image to grayscale image
    cvtColor(*srcImage, enhcImage, CV_RGB2GRAY);
}

/** calcThreshold()
 * Creates binary image fom normal images.
 */
void DIP::calcThreshold(cv::Mat *srcImage, int threshold, int maxValue)
{
    ///Calculate threshold image
    cv::threshold(*srcImage, enhcImage, threshold, maxValue, cv::THRESH_BINARY);
}

/** calcBlobs()
 * Calculate blobs and put them into a vector.
 */
void DIP::calcBlobs()
{

}

/** getEnhancedImage()
 * @return Returns enhanced image.
 */
cv::Mat *DIP::getEnhancedImage()
{
    
    
    return &enhcImage;
}
