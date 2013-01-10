/* 
 * File:   ImageLinkLabel.cpp
 * Author: krigu
 * 
 * Created on January 2, 2013, 7:28 PM
 */


#include "ImageLinkLabel.hpp"

ImageLinkLabel::ImageLinkLabel() {


}

ImageLinkLabel::~ImageLinkLabel() {

}

void ImageLinkLabel::setLink(Link link) {
    this->link = link;
    setPixmap(QPixmap::fromImage(link.image));
}

void ImageLinkLabel::mousePressEvent(QMouseEvent * event) {
    Q_UNUSED(event);
    if (link.href != NULL)
    emit clicked(link.href);
}
