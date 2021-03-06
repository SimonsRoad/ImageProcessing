function [ Sal ] = hc( imgIn )
% ------------------
% Author : smher
% Data   : 2017.7.17
% Description :
%       This file implement the " Global Contrast Based Salient Region
%       Detectioin "
% ------------------
[m, n, z] = size(imgIn);
if z == 3
    imgIn = rgb2gray(imgIn);
end


imgHist = calHist(imgIn);
imgHist = imgHist/(m * n);
imgDist = colorDist(imgHist);

Sal = zeros(m, n);

for i = 1:m
    for j = 1:n
        imgVal = imgIn(i, j) + 1;
        temp = imgDist(imgVal);
        Sal(i, j) = temp;        
    end
end

imshow(Sal, []);
figure;
imshow(imgIn, []);

end

