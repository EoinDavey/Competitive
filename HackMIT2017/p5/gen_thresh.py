import os
import cv2
import numpy as np

for filename in os.listdir('captchas'):
    img = cv2.imread('captchas/'+filename,0)
    out = np.full((50,100),255,np.uint8)
    _, thresh = cv2.threshold(img,200,255,cv2.THRESH_BINARY)
    for x in range(50):
        for y in range(100):
            if thresh[x,y] < 127:
                out[x,y]=0
    cv2.imwrite('caps_thresh/'+filename,(255-out),[cv2.IMWRITE_JPEG_QUALITY,100])
