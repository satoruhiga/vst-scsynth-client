/*{
	"name": "Simple",
}*/

(
SynthDef(\Simple, {| freq=440, amp=1, gate=1 |
	var sig = SinOsc.ar(freq);
	var env = EnvGen.kr(Env.adsr(), gate, doneAction: Done.freeSelf);
	Out.ar(0, Pan2.ar(sig * env, 0.0, amp));
}).add;
)
