var script = require('./PSim');
var fs = require('fs');
gameConfig = fs.readFileSync('gameConfig.tdf', 'utf8');
console.log("GAME");
var teamhandler = new script.CTeamHandler();
var setup = new script.CGameSetup();
console.log("Initialization");
var init = setup.Init(gameConfig);
console.log("Initialization success: " + init);
 
var Obj = setup;
 
 
teamhandler.LoadFromSetup(Obj);
var c = teamhandler.ValidAllyTeam(0);
console.log("ValidAllyTeam: " + c);
 
 
teamhandler.SetAlly(1, 4, true);
console.log("Ally: " + teamhandler.Ally(3, 2));