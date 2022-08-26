import os
import cv2
import numpy as np

mask = cv2.imread('distort_mask.jpg',0)
dist = cv2.resize(mask,(0,0),fx=10,fy=10)
dist = cv2.dilate(dist, np.ones((6,6),np.uint8))

def maskPixelTouchingText(img, msk, x, y):
    if msk[x,y] == 0 and 0 in (img[x+1, y], img[x-1, y], img[x, y+1], img[x, y-1]):
        return True
    else:
        return False

for filename in os.listdir('caps_thresh'):
    img = cv2.imread('caps_thresh/'+filename,0)
    #remove all the mask pixels       
    height, width = img.shape
    for i in range(height):
        for j in range(width):
            if mask[i,j] == 0:
                img[i,j] = 255

    out = img.copy()

    #put some of the mask pixels back into the output image
    for i in range(1, height-1):
        for j in range(1, width-1):
            if maskPixelTouchingText(img, mask, i, j):
                out[i,j] = 0

    out=cv2.resize(out,(0,0),fx=10,fy=10)
    _, out = cv2.threshold(out,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    out=cv2.dilate(out,np.ones((2,2),np.uint8),iterations=1)
    out=cv2.erode(out,np.ones((4,4),np.uint8),iterations=1)
    out=cv2.blur(out,(18,18))
    _, out = cv2.threshold(out,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    out=cv2.dilate(out,np.ones((3,3),np.uint8),iterations=1)
    cv2.imwrite('caps_blur/'+filename,out,[cv2.IMWRITE_JPEG_QUALITY,100])
