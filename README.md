# Coco Browser Engine

Coco is a hobby browser engine which aims to render HTML and CSS files into the screen.

## How it works?

This browser engine takes  HTML(and CSS - optional) file as an input and renders the webpage into the screen. For this several steps are executed during which the streams of characters from the HTML(and CSS) files are converted into a table of tokens. 
Using these tokens, individual nodes are created. 
Nodes can be considered as objects with specific properties(nodes are a separate entity within the document object tree). 
Using these nodes, tree structure called the Document Object Model(DOM) is generated. 
Same steps are taken for the CSS file as well, as a result of which a CSS-Object Mode(CSSOM) is generated. 
Both the DOM and CSSOM are then used to generated a Render Tree. The Render Tree contains all the contents of the HTML elements and how they are to be rendered. 
Using this Render Tree, the layout is finally painted into the screen.
