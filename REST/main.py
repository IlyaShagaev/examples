from flask import Flask, json, jsonify
from settings import *

app = Flask(__name__)

def check(id) -> str: # Проверка на наличие в списке

	users_list = json.load(open('test.json'))
	for user in users_list:
		if user["id"] == id:
			return 'True'
	return 'False'

@app.route('/test/', methods=['GET'])
def get_list():
	return jsonify(users_list)

@app.route('/test/<id>', methods=['GET'])
def get_user(id):
	return check(id)

if __name__ == '__main__':
	app.run(host = REST_HOST, port = REST_PORT)