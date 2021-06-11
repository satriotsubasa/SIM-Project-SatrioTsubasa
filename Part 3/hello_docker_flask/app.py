# app.py - a minimal flask api using flask_restful
from flask import Flask, request, jsonify
from flask_restful import Resource, Api

app = Flask(__name__)
api = Api(app)

latitude = 'x'
longitude = 'x'
gps = 'x'
gsm = 'x'
imei = 'x'
ip = 'x'

@app.route('/', methods=['POST']) 
def postdata():
	req_data = request.json

	global latitude
	global longitude
	global gps
	global gsm
	global imei
	global ip
	
	latitude = req_data['latitude']
	longitude = req_data['longitude']
	gps = req_data['gps']
	gsm = req_data['gsm']
	imei = req_data['imei']
	ip = req_data['ip']
	
	return {"status": "OK"}
	
@app.route('/', methods = ['GET'])
def home():
    return '<p>{},{}</p><p>{},{}</p><p>{}</p><p>{}</p>'.format(latitude, longitude, gps, gsm, imei, ip)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')

