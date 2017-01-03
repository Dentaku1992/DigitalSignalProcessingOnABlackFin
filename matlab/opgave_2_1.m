DATA = imread('./achtergrondveranderen.jpg');

figure
subplot(1,2,1);
image(DATA)
title('Voor kleursverandering')
axis off;

for y=1:600
    for x=1:800
        if DATA(y,x,1)>45 && DATA(y,x,1)<145 
            if DATA(y,x,2)>90 && DATA(y,x,2)<185
                if DATA(y,x,3)>29 && DATA(y,x,3)<108
            DATA(y,x,1) = 180;
            DATA(y,x,2) =  180;
            DATA(y,x,3) = 180;
                end
            end
        end
    end
end

subplot(1,2,2);
image(DATA)
title('Na kleursverandering')
axis off;
