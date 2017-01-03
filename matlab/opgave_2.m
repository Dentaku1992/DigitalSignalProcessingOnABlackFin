StudioBeeld = imread('./achtergrondveranderen.jpg');
Achtergrond = imread('./wolken.jpg');

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