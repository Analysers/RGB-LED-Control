const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

const cors = require('cors');
app.use(cors());

const port = 3000;
app.listen(port);
console.log('\n ------ API running on port ' + port + ' ------');

let dataLed = {
    status: 0,
    R: 0,
    G: 0,
    B: 0
}

app.get('/getDataLed', async (req, res) => {

    try {   

        return res.status(200).send(dataLed);

    } catch(err) {
        return res.status(400).send({error: 'Error'});
    }
});

app.post('/setDataLed', async (req, res) => {

    try {   
        
        console.log(req.body)
        dataLed = req.body;
        return res.status(200).send(req.body);

    } catch(err) {
        return res.status(400).send({error: 'Error'});
    }
});