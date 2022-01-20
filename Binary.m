I = imread('_rsc8847_b.jpg');
BW = imbinarize(I);
figure
imshowpair(I,BW,'montage')