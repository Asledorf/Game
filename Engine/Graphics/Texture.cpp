#include "pch.h"
#include "Texture.h"
#include "Renderer.h"

namespace Engine
{
    bool Texture::Create(const std::string& fileName, void* data)
    {
        //std::cout << "Data: " << data << '\n';
        //auto datum = data;
        this->renderer = (static_cast<Renderer*>(data))->renderer;

        //SDL_Renderer* ff = static_cast<SDL_Renderer*>(data);
        //std::cout << "FF: " << ff << '\n';
        //Renderer* rr = static_cast<Renderer*>(data);
        //std::cout << "RR: " << rr << '\n';

        //std::cout << "OLD Renderer: " << this->renderer <<  '\n';
        //this->renderer = ff;
        //std::cout << "NEW Renderer: " << this->renderer <<  '\n';

        if (renderer == nullptr)
        {
            std::cout << "SDL_CreateRenderer Error (texture.cpp): \n";
            std::cout << SDL_GetError() << std::endl;
            return false;
        }       

        SDL_Surface* surface = IMG_Load(fileName.c_str());
        if (surface == nullptr)
        {
            std::cout << "SDL_CreateSurface Error: \n";
            std::cout << SDL_GetError() << std::endl;
            return false;
        }

        texture = SDL_CreateTextureFromSurface(this->renderer, surface);
        SDL_FreeSurface(surface);
        if (texture == nullptr)
        {
            std::cout << "Nullptr Texture Error: \n";
            std::cout << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    void Texture::Destroy()
    {
        SDL_DestroyTexture(texture);
    }

    void Texture::Draw(const Vector2& position, const Vector2& scale, float angle)
    {
        Vector2 size{ GetSize() };
        size *= scale;

        SDL_Rect rect;
        rect.x = static_cast<int>(position.x);
        rect.y = static_cast<int>(position.y);
        rect.w = static_cast<int>(size.x);
        rect.h = static_cast<int>(size.y);
        SDL_RenderCopyEx(this->renderer, texture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
    }

    void Texture::Draw(const SDL_Rect& source, const Vector2& position, const Vector2& scale, float angle)
    {
        Vector2 size{ source.w,source.h };
        size *= scale;

        SDL_Rect rect;
        rect.x = static_cast<int>(position.x);
        rect.y = static_cast<int>(position.y);
        rect.w = static_cast<int>(size.x);
        rect.h = static_cast<int>(size.y);
        SDL_RenderCopyEx(this->renderer, texture, &source, &rect, angle, nullptr, SDL_FLIP_NONE);
    }

    Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(texture, nullptr, nullptr, &point.x, &point.y);
        return {point.x,point.y};
    }
}