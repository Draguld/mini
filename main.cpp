#include "std.hpp"
#include "sfml.hpp"
#include "ft_type.hpp"
#include "Pixel.hpp"

bool		writeImg(std::string path, Pixel *array, unsigned int const x, unsigned int const y)
{
	std::ofstream	writer;

	if (array == NULL)
		return (false);
	writer.open(path.c_str());
	if (!writer)
	{
		std::cout << "Error to open file : " << path << '\n' << std::flush;
		return(false);
	}
	writer << std::to_string(x) << '\n' << std::to_string(y) << '\n';
	for (unsigned int i = 0; i < x * y; i++)
		writer << array[i].r << array[i].g << array[i].b << array[i].a;
	writer << std::flush;
	writer.close();
	return (true);
}

Pixel	*readImg(std::string path, unsigned int *x, unsigned int *y)
{
	Pixel			*array;
	std::ifstream	reader;
	std::string		resX;
	std::string		resY;
	
	if (path.empty())
		return (NULL);
	reader.open(path.c_str());
	if (!reader)
	{
		std::cout << "Error to open file : " << path << '\n' << std::flush;
		return (NULL);
	}
	std::getline(reader, resX);
	std::getline(reader, resY);
	*x = std::stoi(resX);
	*y = std::stoi(resY);
	if (*x == 0 || *y == 0)
		return (NULL);
	array = new Pixel[*x * *y];	
	for (unsigned int i = 0; i < *x * *y; i++)
	{
		char buf;
		reader.get(buf);
		array[i].r = (unsigned char)buf;		
		reader.get(buf);
		array[i].g = (unsigned char)buf;		
		reader.get(buf);
		array[i].b = (unsigned char)buf;		
		reader.get(buf);
		array[i].a = (unsigned char)buf;		
	}
	reader.close();
	return (array);
}

void	drawImg(Pixel *array, unsigned int xRes, unsigned int yRes)
{
	sf::RenderWindow	win;
	sf::Event			event;
	sf::Image			img;
	sf::Texture			tex;
	sf::VertexArray		vertices(sf::Quads, 4);

	if (array == NULL || xRes == 0 || yRes == 0)
		return;
	img.create(xRes, yRes, sf::Color(0, 0, 0, 0));

	for(unsigned int x = 0; x < xRes; x++)
		for(unsigned int y = 0; y < yRes; y++)
		{
			img.setPixel(x, y, sf::Color(array[x + y * xRes].r, array[x + y * xRes].g, array[x + y * xRes].b, array[x + y * xRes].a));
		}

	tex.loadFromImage(img);

		vertices[0].position = sf::Vector2f(0, 0);
		vertices[1].position = sf::Vector2f(xRes, 0);
		vertices[2].position = sf::Vector2f(xRes, yRes);
		vertices[3].position = sf::Vector2f(0, yRes);
		
		vertices[0].texCoords = sf::Vector2f(0, 0);
		vertices[1].texCoords = sf::Vector2f(xRes, 0);
		vertices[2].texCoords = sf::Vector2f(xRes, yRes);
		vertices[3].texCoords = sf::Vector2f(0, yRes);


	win.create(sf::VideoMode(xRes, yRes), "drawImg");
	win.setFramerateLimit(30);

	while (win.isOpen())
	{
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
		}
		win.clear(sf::Color::Black);
		win.draw(vertices, &tex);
		win.display();
	}
}

Pixel	*loadFromFileImg(std::string path, unsigned int *x, unsigned int *y)
{
	sf::Image		img;
	Pixel			*array;

	if (!img.loadFromFile(path))
		return (NULL);
	*x = img.getSize().x;
	*y = img.getSize().y;
	array = new Pixel[*x * *y];

	for (unsigned int ix = 0; ix < *x; ix++)
		for (unsigned int iy = 0; iy < *y; iy++)
		{
			sf::Color 	c_buf = img.getPixel(ix, iy);
			Pixel		p_buf = Pixel(c_buf.r, c_buf.g, c_buf.b, c_buf.a);
			array[ix + iy * *x] = p_buf;
		}
	return (array);
}

int main()
{
	Pixel			*array;
	unsigned int	x;
	unsigned int	y;

	array = loadFromFileImg("demo.png", &x, &y);
	writeImg("demo.cpy", array, x, y);
	delete[] array;
	array = readImg("demo.cpy", &x, &y);
	drawImg(array, x, y);
	return (0);
}
