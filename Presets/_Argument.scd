/*{
	"name": "Argument",
    "args": [
        { "name": "lfo", "min": 0.1, "max": 30 }
    ]
}*/

(
SynthDef(\Argument, {| freq=440, amp=1, gate=1, lfo=0.1 |
	var sig = SinOsc.ar(freq) * SinOsc.ar(lfo, 0.5, 0.5);
	var env = EnvGen.kr(Env.adsr(), gate, doneAction: Done.freeSelf);
	Out.ar(0, Pan2.ar(sig * env, 0.0, amp));
}).add;
)
