# Arduino-keypad-sheild-template
this is a simple to edit code that make using the keypad sheild easier
# Creat objects
First write in the line 16 the number of objets you want
for example if you want 2 numbers with a cursor you would need 3 objects #define Size 3
# Setup objects
in line 30 after //Setup default Pos & Val comment write the objects starting positions and values by editing obj array and Pos array
the Pos array work linearly Pos = [x,y,x1,y1,...] so if you have 2 objects you should give x of objet 1 in Pos[0] y of objet 1 in Pos[1] x of objet 2 in Pos[2] y of objet 2 in Pos[3] and to set the text change the obj[] value so to have obj1 as "A" just write obj[0] = "A"
# Get Input
there is a function called GetKey() that return a bool you just need to specifie the button to check for example:
GetKey(Up) will return true if up is pressed   !dont write Up as a string, there is premade variables called Up,Down,Left,Right,Any,Sel
# Move Objects and edit Values
To move an object all you need to do is change Pos[] val so to move obj1 Pos you just do Pos[0] +=1 that will move it to the right
to change its value just do obj[0] = "what you want"
# Refresh display
To refresh the display and show the modifications just use Draw(obj,Pos) this function take the objects val in obj and display them with the correct positions in Pos so its possible to make mutiple pages by creating custom obj and pos arrays 
