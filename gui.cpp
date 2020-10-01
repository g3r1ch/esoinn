#include "gui.h"


Gui::Gui(int x, int y, string name) {
	window.create(sf::VideoMode(x, y), name);
	weight = x;
	height = y;
}

//void Gui::matrix_from_double_vec(vector<double> aInp,int xx,int yy) {
//	sf::VertexArray quad(sf::Quads, 4);
//	window.clear();
//	int gen = 0;
//	quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//	quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//	quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//	quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//
//	quad[0].position = sf::Vector2f(xx * 10 + 2, 0);
//	quad[1].position = sf::Vector2f(xx * 10 + 10, 0);
//	quad[2].position = sf::Vector2f(xx * 10 + 10, 8);
//	quad[3].position = sf::Vector2f(xx * 10 + 2, 8);
//
//	window.draw(quad);
//	//cout << aInp[0] << endl;
//	for (int x = 0; x < (xx - 1) * 10; x += 10) {
//		for (int z = 0; z < yy * 10; z += 10, gen++) {
//			
//			//cout << weights[18]<<endl;
//			/*if (aInp[gen] < 0) {
//				quad[0].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//				quad[1].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//				quad[2].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//				quad[3].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//			}
//			else if (aInp[gen] > 0) {
//				quad[0].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//				quad[1].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//				quad[2].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//				quad[3].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//			}
//			else {
//				quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//				quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//				quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//				quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//			}*/
//			/*quad[0].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//			quad[1].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//			quad[2].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//			quad[3].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);*/
//			/*quad[0].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//			quad[1].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//			quad[2].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//			quad[3].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);*/
//			quad[0].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//			quad[1].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//			quad[2].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//			quad[3].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//			//quad[3].color = sf::Color::Color(round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100));
//			//if (gen == round(f + u)) {
//			//	quad[0].color = sf::Color::Red;
//			//	quad[1].color = sf::Color::Red;
//			//	quad[2].color = sf::Color::Red;
//			//	quad[3].color = sf::Color::Red;
//			//}
//			//if (gen == ol.process(ans)) {
//			//	quad[0].color = sf::Color::Green;
//			//	quad[1].color = sf::Color::Green;
//			//	quad[2].color = sf::Color::Green;
//			//	quad[3].color = sf::Color::Green;
//			//}
//			//cout << x * 2 + z / 10 << endl;
//
//			//(x + z) / 10
//			quad[0].position = sf::Vector2f(x, z);
//			quad[1].position = sf::Vector2f(x, z + 8);
//			quad[2].position = sf::Vector2f(x + 8, z + 8);
//			quad[3].position = sf::Vector2f(x + 8, z);
//
//			window.draw(quad);
//		}
//	}
//	for (int z = 0; z < (yy - 1) * 10; z += 10, gen++) {
//
//		//cout << weights[18]<<endl;
//		/*if (aInp[gen] < 0) {
//			quad[0].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//			quad[1].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//			quad[2].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//			quad[3].color = sf::Color::Color((255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10), (255 / 2) * (1 + (aInp[gen]) / 10));
//		}
//		else if (aInp[gen] > 0) {
//			quad[0].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//			quad[1].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//			quad[2].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//			quad[3].color = sf::Color::Color((255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10), (255 / 2) * ((aInp[gen]) / 10));
//		}
//		else {
//			quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//			quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//			quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//			quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
//		}*/
//		/*quad[0].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//		quad[1].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//		quad[2].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
//		quad[3].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);*/
//		/*quad[0].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//		quad[1].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//		quad[2].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);
//		quad[3].color = sf::Color::Color((weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255, (weights[gen]) / 10 * 255);*/
//		quad[0].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//		quad[1].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//		quad[2].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//		quad[3].color = sf::Color::Color(abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)), abs(round(aInp[gen] * 100)));
//		//quad[3].color = sf::Color::Color(round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100), round(ans[x * 2.5 + z / 10] * 100));
//		//if (gen == round(f + u)) {
//		//	quad[0].color = sf::Color::Red;
//		//	quad[1].color = sf::Color::Red;
//		//	quad[2].color = sf::Color::Red;
//		//	quad[3].color = sf::Color::Red;
//		//}
//		//if (gen == ol.process(ans)) {
//		//	quad[0].color = sf::Color::Green;
//		//	quad[1].color = sf::Color::Green;
//		//	quad[2].color = sf::Color::Green;
//		//	quad[3].color = sf::Color::Green;
//		//}
//		//cout << x * 2 + z / 10 << endl;
//
//		//(x + z) / 10
//		quad[0].position = sf::Vector2f(xx * 10 - 9, z);
//		quad[1].position = sf::Vector2f(xx * 10 - 9, z + 8);
//		quad[2].position = sf::Vector2f(xx * 10 - 1, z + 8);
//		quad[3].position = sf::Vector2f(xx * 10 - 1, z);
//
//		window.draw(quad);
//	}
//	//window.display();
//}
//
//int Gui::graphik(vector<double> aInp) {
//	if (aInp.size() > weight)
//		return 1;
//
//	window.clear();
//
//	sf::VertexArray line(sf::Lines, 2);
//	line[0].color = sf::Color::White;
//	line[1].color = sf::Color::White;
//
//	//int gen = 0;
//
//	for (int i = 0, gen = 0; gen < aInp.size()-1; i+=2,gen++) {
//		/*if (0==(abs(aInp[gen]) * 500))
//			cout << "FFF" << endl;*/
//		line[0].position = sf::Vector2f(i, height - abs(aInp[gen]) * 500);
//		line[1].position = sf::Vector2f(i + 2, height - abs(aInp[gen + 1]) * 500);
//		window.draw(line);
//	}
//
//	return 0;
//}

void Gui::matrix_for_maps(vector<vector<double>> matrix, bool color) {
	sf::CircleShape point(2);
	for (int i = 0; i < matrix.size(); i++) {
		if (color == true) {
			point.setFillColor(sf::Color(255, 0, 0));
		}
		else {
			point.setFillColor(sf::Color(0, 255, 0));
		}
		point.setPosition(sf::Vector2f(matrix[i][0] * weight, matrix[i][1] * height));
		window.draw(point);
	}
}

void Gui::render() {
	window.display();
}

Gui::EventType Gui::evnt() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
			return Gui::EventType::CLOSE;
		}
		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
				return Gui::EventType::CLOSE;
			}
			else if (event.key.code == sf::Keyboard::P) {
				return Gui::EventType::PAUSE;
			}
			else if (event.key.code == sf::Keyboard::R) {
				return Gui::EventType::PRINT;
			}
		}
	}
	return Gui::EventType::NON;
}

int Gui::isOpen() {
	if (window.isOpen())
		return 1;

	return 0;
}

void Gui::clear() {
	window.clear();
}
