var async = require("async");
var express = require("express");
var http = require("http");

function SampleServer() {
}

SampleServer.prototype.init = function (opts,cb_fn) {
    "use strict";
    var self = this;
    async.series([
        self.validateOpts.bind(self,opts),
        self.initWebServer.bind(self),
        self.registerRoutes.bind(self)
    ],
    function (err) {
        cb_fn(err);
        return;
    });
}

SampleServer.prototype.validateOpts = function (opts, cb_fn) {
    var self = this;
    if (!(opts && opts.port)) {
        cb_fn("invalid opts");
        return;
    }

    self.port = opts.port;
    self.id = 0;
    cb_fn(null);
    return;
}

SampleServer.prototype.initWebServer = function (cb_fn) {
    var self = this;
    self.app = new express();
    self.httpServer = http.createServer(self.app);
    self.httpServer.listen(self.port);
    cb_fn(null);
    return;
}

SampleServer.prototype.registerRoutes = function (cb_fn) {
    var self = this;
    self.app.get("/test", function (req,res) {
        res.status(200).send({"id":self.id++});
        return;
    });
    cb_fn(null);
    return;
}

SampleServer.prototype.start = function (cb_fn) {
    cb_fn(null);
    return;
}

function test() {
    var server = new SampleServer();
    async.series([
        server.init.bind(server,{"port":9999}),
        server.start.bind(server)
    ],
    function (err) {
        if (err) {
            console.log("Error in starting my server");
            return;
        }
        console.log("Server started successfully");
    });
}

test();
