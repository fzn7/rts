var script = require('./Sim');
var fs = require('fs');
gameConfig = fs.readFileSync('gameConfig.tdf', 'utf8');

var teamhandler = new script.CTeamHandler();
var TdfParser = new script.TdfParser();
var setup = new script.CGameSetup();
var init = setup.Init(gameConfig);
console.log("Initialization success: " + init);
var Obj = setup;

teamhandler.SetAlly(1, 4, true);
console.log(teamhandler.Ally(3, 2));

teamhandler.LoadFromSetup(Obj);
var c = teamhandler.ValidAllyTeam(0);
console.log(c);
