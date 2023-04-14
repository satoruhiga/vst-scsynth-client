
OSCRPC {
	var <> onOSCMessage;

	*open {
		var self = OSCRPC.new;
		self.onOSCMessage = { |msg, time, replyAddr, recvPort|
			if (msg[0] == '/eval') {
				var result;
				for (1, msg.size - 1, { |i|
					var code = msg[i].asString(4096);
					("🎹:" + code).postln;
					result = History.eval(code);
					("-> 🎵:" + result).postln;
					replyAddr.sendMsg('/reply', result);
				});
			}
		};

		("🎵:Open OSC-RPC port at port:" + NetAddr.langPort).postln;

		thisProcess.addOSCRecvFunc(self.onOSCMessage);
		^self;
	}

	close {
		thisProcess.removeOSCRecvFunc(this.onOSCMessage);
	}

	prepareForProxySynthDef { ^this }
}