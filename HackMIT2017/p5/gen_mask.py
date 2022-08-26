import os
import cv2
import numpy as np

out = np.full((50,100),255,np.uint8)

for filename in os.listdir('captchas'):
    img = cv2.imread('captchas/'+filename,0)
    _, thresh = cv2.threshold(img,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    for x in range(50):
        for y in range(100):
            if thresh[x,y] < 127:
                out[x,y]=0

cv2.imwrite('distort_mask.jpg',(255-out),[cv2.IMWRITE_JPEG_QUALITY,100])
