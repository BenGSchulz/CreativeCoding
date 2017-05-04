# CreativeCoding
Repo for EDPX 3701 Creative Coding projects

Benjamin Schulz
benjamin.schulz@du.edu

EDPX 3701 Creative Coding

Exercise 1: Face
—- Create a face using at least 10 graphical elements.

Exercise 2: Animate
—- Create a project with mouse interaction, key interaction, animation.

Exercise 3: Add-ons
—- Create a project utilizing at least 2 OF add-ons in conjunction.
—- Utilized ofxFluid, ofxGUI, ofxFX add-ons


PROJECT 1: LYRICAL
-- Create a data visualization/generative art piece using OpenFrameworks

-- I made a lyric scroller for charted songs in the US. You can change which page of the chart/how many songs are included in the URL    		 request. I was just inspired by the fact that I wanted to do something with lyrics. I like lyric sites like genius and musixmatch and 		 so those got me thinking of the idea to use their API (I used musixmatch). I ended up doing very little compared to my initial idea and 		even then there are still many bugs. I am not familiar with c++ specifics and I feel that took a big chunk out of my project's 		 			 potential.

-- BUILD INSTRUCTIONS -> use ofxJSON https://github.com/jeffcrouse/ofxJSON for addon. 

-- USAGE -> Use the mouse to interact with button at start. Then use the mouse to click on the song you would like to see the lyrics for. 	 (This is buggy, as multiple songs can be highlighted at once and the lyrics get confused sometimes, also the buttons double click so 		 they can send you to a song immediately if it's bubble happens to be where your mouse is when you click the starting button). There are 	  also back buttons on the chart and lyric pages that suffer the same double clicking bug. To change the number of songs on the chart, 		 find the URL request in the ChartView.cpp and change the page_size value. 

-- VIDEO -> https://youtu.be/wBiO7DyM8us

