DATA = imread('C:\Users\Gert-Jan\Desktop\DSPmatlab\GroteSmurf.jpg');

figure
subplot(1,2,1);
image(DATA)
title('Voor kleursverandering')
axis off;

for y=1:300
    for x=1:300
        if DATA(y,x,1)>0 && DATA(y,x,1)<115 && DATA(y,x,2)>100 && DATA(y,x,2)<200 && DATA(y,x,3)>0 && DATA(y,x,3)<255
            DATA(y,x,1) = 255;
            DATA(y,x,2) =  DATA(y,x,2)+54;
            DATA(y,x,3) = abs(DATA(y,x,3)-215);
        end
    end
end

subplot(1,2,2);
image(DATA)
title('Na kleursverandering')
axis off;