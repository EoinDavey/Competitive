import os
import cv2
import numpy as np

img = cv2.imread('distort_mask.jpg',0)

for x in range(50):
    for y in range(100):
        print img[x,y]
