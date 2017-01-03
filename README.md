#Digital Signal Processing On BlackFin

In this project a BlackFin Development kit is used to manipulate realtime video content. In this project the BlackFin BF-561 DSP processor is used. 

##Project goal

The goal of this project is to apply a color conversion on a real-time video signal using the Blackfin BF-561 DSP processor. This video signal is coming from a digital camera, and sent to the BlackFin via the NTSC protocol. The color change that must be made is a transformation of blue (color of a Smurfs) to yellow.

First, several DSP algorithms were implemented in Matlab in order to test, evaluate and simulate them. After the Matlab simulation the algorithm is implemented on the DSP processor using the programming language C ++.

In addition to the practical implementation, a small study of color spaces and -conversions, as well as a theoretical study of techniques which can increase the performance and the quality of the final result by using the same hardware, was made.

##Used techniques

###Line processing
![Line processing](https://github.com/Dentaku1992/DigitalSignalProcessingOnABlackFin/raw/master/verslag/VideoProcessing/tex/chapters/Chapter4/Images/DMA_line_processing.png)

###Macro block processing
![Macro block processing](https://raw.githubusercontent.com/Dentaku1992/DigitalSignalProcessingOnABlackFin/master/verslag/VideoProcessing/tex/chapters/Chapter4/Images/DMA_block_matrix.png)

###Interframe processing
![Interframe processing](https://github.com/Dentaku1992/DigitalSignalProcessingOnABlackFin/raw/master/verslag/VideoProcessing/tex/chapters/Chapter4/Images/DMA_interframe_processing.png)

##General overview
![General overview](https://raw.githubusercontent.com/Dentaku1992/DigitalSignalProcessingOnABlackFin/master/verslag/VideoProcessing/tex/chapters/Chapter2/Images/implementationOverview.png)

#Authors
Gert-Jan Andries - info@gertjanandries.com - www.gertjanandries.com

Nick Steen 

Xavier Dejager