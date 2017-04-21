#! /usr/bin/python
import scrapy
from bs4 import BeautifulSoup

class MagicSpider(scrapy.Spider):
    name = 'townhall'
    start_urls = []
    URL = 'https://townhallproject.com/#events-table'
    file_name = ''

    def __init__(self):
        self.start_urls.append(self.URL)
        self.file_name = "html.log" #raw_input("input name of file: ")

    def parse( self, response):
        html_dump = open(self.file_name, "w")
        yield response
        soup = BeautifulSoup(response.text, 'lxml')
        alphabet = soup.find_all("li", class_="event-row list-group-item")
        for li in alphabet:
            html_dump.write(li.text)
        html_dump.write(soup.prettify("utf-8"))
