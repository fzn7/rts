var script = require('./PSim');


var teamhandler = new script.CTeamHandler();

var setup = new script.CGameSetup();
//setup.GetTeamStartingDataCont();
//var Setup = setup.ptr;

//teamhandler.LoadFromSetup(Setup);

var c = teamhandler.ValidAllyTeam(1);
console.log(c);
