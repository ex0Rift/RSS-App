import requests
from bs4 import BeautifulSoup

def Scrape(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    return soup

soup = Scrape('https://www.example.com')

print(soup.select_one('p').text)