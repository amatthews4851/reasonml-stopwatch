const chokidar = require("chokidar");
const { exec } = require("child_process");

// One-liner for current directory
chokidar.watch("./lib").on("all", (event, path) => {
  exec("rsync -a ./lib/es6/reason/ ./src");
});
