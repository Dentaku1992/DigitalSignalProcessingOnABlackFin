%\lstinputlisting[caption=Matlab-code \'e\'erste aanpak]{Smurf_1.m}
%\lstinputlisting[caption=Matlab-code tweede aanpak]{Smurf_2.m}
%\lstinputlisting[caption=Matlab-code achtergrond veranderen]{opgave_2_1.m}
%lstinputlisting[caption=Matlab-code achtergrond veranderen]{opgave_2_extra.m}

clear all
clc

StudioBeeld = imread('C:\Users\Gert-Jan\Desktop\DSPmatlab\achtergrondveranderen.jpg');
Achtergrond = imread('C:\Users\Gert-Jan\Desktop\DSPmatlab\wolken.jpg');
Eindresultaat =  StudioBeeld;

figure
subplot(1,3,1);
image(Achtergrond)
title('Achtergrondafbeelding')
axis off;

subplot(1,3,2);
image(StudioBeeld)
title('Studiobeeld voor verandering')
axis off;

%zet kleurwaarden om naar percentage (schaal van 0-255 --> 0-1)
KleurPercentage = double( StudioBeeld)/255;

%groenheid berekenen van 3 kleurkanalen Groen * (groen-rood) * (groen-blauw)
GroenWaarde = KleurPercentage(:,:,2).*(KleurPercentage(:,:,2)-KleurPercentage(:,:,1)).*(KleurPercentage(:,:,2)-KleurPercentage(:,:,3));
%treshold om beter eindresultaat te bereiken. --> er is niet 1 tint groen,
%maar meerdere.
Treshold = 0.8*mean(GroenWaarde(GroenWaarde>0));
IsGroen = GroenWaarde > Treshold;

for i = 1:3
    % sla de rgb waarde van de achtergrond op
    rgbValAchtergrond = Achtergrond(:,:,i);
    % sla de rgb waarde van het studiobeeld op
    rgbValStudioBeeld =  StudioBeeld(:,:,i);
    %logische vergelijking. Als het studiobeeld groen is dan moet de
    %achtergrond op het studiobeeld geplaatst worden
    rgbValStudioBeeld(IsGroen) = rgbValAchtergrond(IsGroen);
    % sla op in eindresultaat
    Eindresultaat(:,:,i) = rgbValStudioBeeld;
end

subplot(1,3,3);
image(Eindresultaat)
title('Studiobeeld na verandering')
axis off;


 
%DATA = imread('C:\Users\Nick\Desktop\Opgave_Matlab_VideoProcessing\Opgave_Matlab_VideoProcessing\achtergrondveranderen.jpg');
% 
% DATA = imread('C:\Users\Gert-Jan\Desktop\DSPmatlab\achtergrondveranderen.jpg');
% 
% %image(DATA);
% 
% figure
% subplot(1,2,1);
% image(DATA)
% title('Voor kleursverandering')
% axis off;
% 
% for y=1:600
%     for x=1:800
%         if DATA(y,x,1)>45 && DATA(y,x,1)<145 % &&  && 
%             if DATA(y,x,2)>90 && DATA(y,x,2)<185
%                 if DATA(y,x,3)>29 && DATA(y,x,3)<108
%             DATA(y,x,1) = 180;
%             DATA(y,x,2) =  180;
%             DATA(y,x,3) = 180;
%                 end
%             end
%         end
%     end
% end
% 
% subplot(1,2,2);
% image(DATA)
% title('Na kleursverandering')
% axis off;

%image(DATA);

%DATA = imread('C:\Users\Nick\Desktop\Opgave_Matlab_VideoProcessing\Opgave_Matlab_VideoProcessing\GroteSmurf_white.jpg');

% DATA = imread('C:\Users\Gert-Jan\Desktop\DSPmatlab\GroteSmurf.jpg');
% 
% %image(DATA);
% 
% figure
% subplot(1,2,1);
% image(DATA)
% title('Voor kleursverandering')
% axis off;
% 
% for y=1:300
%     for x=1:300
%         if DATA(y,x,1)>0 && DATA(y,x,1)<115 && DATA(y,x,2)>100 && DATA(y,x,2)<200 && DATA(y,x,3)>0 && DATA(y,x,3)<255
%             DATA(y,x,1) = 255;
%             DATA(y,x,2) =  DATA(y,x,2)+54;
%             DATA(y,x,3) = abs(DATA(y,x,3)-215);
%         end
%     end
% end
% 
% subplot(1,2,2);
% image(DATA)
% title('Na kleursverandering')
% axis off;

%image(DATA);


%rotatedDATA = imrotate(DATA, 180);
%flipDATA = flipdim(DATA, 1);
%image(rotatedDATA);
%image(flipDATA);

% figure(1);

% while 1
%     for i=1:360
%         for y=1:300
%             for x=1:300
%                 if(DATA(y,x,1)<250 || DATA(y,x,2)<250 || DATA(y,x,3)<250)
%                     DATA(y,x,1) = 255-DATA(y,x,1);
%                     DATA(y,x,2) = 255-DATA(y,x,2);
%                     DATA(y,x,3) = 255-DATA(y,x,3);
%                 end
%                 if(DATA(y,x,1)>250 && DATA(y,x,2)>250 && DATA(y,x,3)>250)
%                     DATA(y,x,1) = 0;
%                     DATA(y,x,2) = 0;
%                     DATA(y,x,3) = 0;
%                 end
%             end
%         end
%         image(imrotate(DATA, i));
%         %image(DATA);
%         drawnow();
%     end
%     for i=360:-1:1
%         for y=1:300
%             for x=1:300
%                 if(DATA(y,x,1)<250 || DATA(y,x,2)<250 || DATA(y,x,3)<250)
%                     DATA(y,x,1) = 255-DATA(y,x,1);
%                     DATA(y,x,2) = 255-DATA(y,x,2);
%                     DATA(y,x,3) = 255-DATA(y,x,3);
%                 end
%                 if(DATA(y,x,1)>250 && DATA(y,x,2)>250 && DATA(y,x,3)>250)
%                     DATA(y,x,1) = 0;
%                     DATA(y,x,2) = 0;
%                     DATA(y,x,3) = 0;
%                 end
%             end
%         end
%         image(imrotate(DATA, i));
%         %image(DATA);
%         drawnow();
%     end
% end