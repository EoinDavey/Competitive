import cv2

img1 = cv2.imread('caps_thresh/0a00b859137c4f328f04d44d771e2d00.jpg' ,0)
mask = cv2.imread('distort_mask.jpg' ,0)

def maskPixelTouchingText(img, msk, x, y):
    if msk[x,y] == 0 and 0 in (img[x+1, y], img[x-1, y], img[x, y+1], img[x, y-1]):
        return True
    else:
        return False
    
#remove all the mask pixels       
height, width = img1.shape
for i in range(height):
    for j in range(width):
        if mask[i,j] == 0:
            img1[i,j] = 255

img2 = img1.copy()

#put some of the mask pixels back into the output image
for i in range(1, height-1):
    for j in range(1, width-1):
        if maskPixelTouchingText(img1, mask, i, j):
            img2[i,j] = 0

cv2.imwrite('test.jpg',img2)
