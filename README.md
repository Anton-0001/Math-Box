<h1>Arduino-Controlled Phone Locker</h1>

<h2>Description</h2>
The Davy Phones Locker is an Arduino-powered system designed to lock a phone in a secure box before bed, requiring users to set an alarm on their phone and solve randomized math equations to unlock it in the morning, encouraging wakefulness and mental engagement. The project integrates a keypad for user input, an LCD screen for displaying equations and feedback, and C++ logic to generate and validate equations, with Arduino code managing hardware functionality.
<br />


<h2>Languages Used</h2>

- <b>C++</b> 
- <b>Arduino</b>

<h2>Environments Used </h2>

- <b>Windows 10</b> (21H2)

<h2>User Interface Walkthrough:</h2>

<p align="center">
Keypad & LCD integration w/ Arduino: <br/>
<img src="https://i.imgur.com/kr72NwX.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />
<br />
The equation is displayed awaiting user input:  <br/>
<img src="https://i.imgur.com/6nNZykF.png" width="80%" alt="Disk Sanitization Steps"/>
<br />
<br />
User inputs an answer using the keypad & presses '#' which functions as the enter key, If correct: a "Correct" message is displayed and the motor responsible for the locking mechanism is activated(not shown) <br/>
<img src="https://i.imgur.com/rAA9uet.png" alt="Disk Sanitization Steps"/>
<br />
<br />
If Wrong, Error is displayed and a new equation must be solved:  <br/>
<img src="https://i.imgur.com/MMZINkA.png"/>
<br />
<img src="https://i.imgur.com/scY0UyV.png"/>
  
</p>

<!--
 ```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```
--!>
