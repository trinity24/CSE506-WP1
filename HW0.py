# -*- coding: utf-8 -*-
"""
Spyder Editor

Sharmila Duppala
"""
import cv2

img1= cv2.imread('/Users/sharmila24/Downloads/Federer_AUS2017FINAL.jpeg')

cv2.imshow(img1)
cv2.waitKey(0)


img2= cv2.imread('/Users/sharmila24/Downloads/hardworkROGER.jpg')

print "Pixel value befpre incrementing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)
for i in range(len(img1)):  
    for j in range(len(img1[0])):
        for k in range((len(img1[0,0]))):
            img1[i,j,k]+=30

print "Pixel value after incrementing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)



print "Pixel value befpre decrementing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)
for i in range(len(img1)):
    for j in range(len(img1[0])):
        for k in range((len(img1[0,0]))):
            img1[i,j,k]-=30

print "Pixel value after decrementing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)

print "Pixel value befpre  the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)
for i in range(len(img1)):
    for j in range(len(img1[0])):
        for k in range((len(img1[0,0]))):
            img1[i,j,k]-=30

print "Pixel value after decrementing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)

print "Pixel value befpre multiplying the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)
for i in range(len(img1)):
    for j in range(len(img1[0])):
        for k in range((len(img1[0,0]))):
            img1[i,j,k]*=2

print "Pixel value after multiplying the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)

print "Pixel value befpre dividing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)
for i in range(len(img1)):
    for j in range(len(img1[0])):
        for k in range((len(img1[0,0]))):
            img1[i,j,k]/=2

print "Pixel value after dividing the RGB values : ",img1[100,100]
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg')
cv2.waitKey(0)

res = cv2.resize(img1,None,fx=0.5, fy=0.5, interpolation = cv2.INTER_AREA)
cv2.imshow('/Users/sharmila24/Downloads/hardworkROGER.jpg' ,res)

